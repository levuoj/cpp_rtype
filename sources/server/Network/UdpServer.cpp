//
// Created by levuoj on 12/01/18.
//

#include "server/Network/UdpServer.hpp"

Server::UdpServer::UdpServer(Mediator &mediator, boost::asio::io_service &io_service) : ANetwork(mediator), socket_(io_service, udp::endpoint(udp::v4(), 1024))
{
    std::cout << "BEGIN consturctor" << std::endl;
    start_receive();
    Event ev;
    ev.type = EventType::STARTGAME;
    ev.subType = SubType::FROMCLIENT;
    ev.datas.push_back("lol");
    sending(ev);
    std::cout << "END consturctor" << std::endl;
}

void Server::UdpServer::start_receive() {
    socket_.async_receive_from(
            boost::asio::buffer(recv_buffer_), remote_endpoint_,
            boost::bind(&UdpServer::handle_receive, this,
                        boost::asio::placeholders::error,
                        boost::asio::placeholders::bytes_transferred));
}

void Server::UdpServer::handle_receive(const boost::system::error_code &error,
                                       std::size_t  bytes_transferred)
{
    std::cout << "BEGIN " << __FUNCTION__ << std::endl;
    if (!error || error == boost::asio::error::message_size)
    {
        std::cout.write(recv_buffer_, bytes_transferred);
        std::cout << std::endl;
        sending(ProtocolHandler::ByteArrayToEv(recv_buffer_, bytes_transferred));
        memset(recv_buffer_, 0, sizeof(recv_buffer_));
        sender(remote_endpoint_);

        std::cout << "END " << __FUNCTION__ << std::endl;
        start_receive();
    }
}

void Server::UdpServer::handle_send(boost::shared_ptr<std::string> message,
                                    const boost::system::error_code & /*error*/,
                                    std::size_t /*bytes_transferred*/)
{
    std::cout << "BEGIN " << __FUNCTION__ << std::endl;
    std::cout << message << std::endl;
    std::cout << "END " << __FUNCTION__ << std::endl;
}

void Server::UdpServer::sender(udp::endpoint const& ep)
{
    std::cout << "BEGIN " << __FUNCTION__ << std::endl;

    Event event;
    event.subType = FROMSERVER;
    event.type = UPDATE;
    event.datas.push_back("anthony");
    event.datas.push_back("commencer");

    boost::shared_ptr<std::string> message(new std::string(ProtocolHandler::EventToByteArray(event)));

    socket_.async_send_to(boost::asio::buffer(*message), ep,
                          boost::bind(&UdpServer::handle_send, this, message,
                                      boost::asio::placeholders::error,
                                      boost::asio::placeholders::bytes_transferred));
    std::cout << "END " << __FUNCTION__ << std::endl;
}

void Server::UdpServer::receive(Event const & event)
{
    std::cout << "BEGIN " << __FUNCTION__ << std::endl;

    for (auto it : event.datas)
        std::cout << it << std::endl;

    if (event.subType == SubType::FROMSERVER)
        sender(remote_endpoint_);

    switch (event.type)
    {
        case EventType::UPDATE :
            sender(remote_endpoint_);
            break;
        case EventType::STARTGAME :
            sender(remote_endpoint_);
            break;
        case EventType::INPUT :
            sender(remote_endpoint_);
            break;
        default:
            break;
    }

    std::cout << "END " << __FUNCTION__ << std::endl;
}

void Server::UdpServer::launch()
{
    std::cout << "START " << __FUNCTION__ << std::endl;

    std::cout << "END " << __FUNCTION__ << std::endl;
}
