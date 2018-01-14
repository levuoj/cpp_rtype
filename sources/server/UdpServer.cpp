//
// Created by levuoj on 12/01/18.
//

#include <memory.h>

#include "server/UdpServer.hpp"

Server::UdpServer::UdpServer(Mediator &mediator, boost::asio::io_service &io_service) : AManager(mediator), socket_(io_service, udp::endpoint(udp::v4(), 1024))
{
    start_receive();
}

void Server::UdpServer::start_receive() {
    socket_.async_receive_from(
            boost::asio::buffer(recv_buffer_), remote_endpoint_,
            boost::bind(&UdpServer::handle_receive, this,
                        boost::asio::placeholders::error,
                        boost::asio::placeholders::bytes_transferred));
}

void Server::UdpServer::handle_receive(const boost::system::error_code &error,
                                       std::size_t bytes_transferred)
{
    if (!error || error == boost::asio::error::message_size)
    {
        std::cout << bytes_transferred << std::endl;
        unsigned short a;
        std::memcpy(&a, std::string(recv_buffer_).substr(0, 2).c_str(), sizeof(unsigned short));
        std::cout << a << std::endl;
        std::cout.write(recv_buffer_, bytes_transferred);
        std::cout << std::endl;

        send(remote_endpoint_);

        start_receive();
    }
}

void Server::UdpServer::handle_send(boost::shared_ptr<std::string> /*message*/,
                                    const boost::system::error_code & /*error*/,
                                    std::size_t /*bytes_transferred*/) {}

void Server::UdpServer::send(udp::endpoint const& ep)
{
    std::string s1 = "220";
    s1.append(1, '\0');
    s1.append("lol");
    s1.append(1, '\0');
    s1.append("mdr");

    boost::shared_ptr<std::string> message(new std::string(s1));

    socket_.async_send_to(boost::asio::buffer(*message), remote_endpoint_,
                          boost::bind(&UdpServer::handle_send, this, message,
                                      boost::asio::placeholders::error,
                                      boost::asio::placeholders::bytes_transferred));
}

void Server::UdpServer::receive(Event const & event)
{
    switch (event.type)
    {
        //case EventType :
            send(remote_endpoint_);
            break;
        default:
            break;
    }
}