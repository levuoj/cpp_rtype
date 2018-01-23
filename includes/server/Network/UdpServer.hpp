//
// Created by levuoj on 12/01/18.
//

#ifndef CPP_RTYPE_UDPSERVER_HPP
#define CPP_RTYPE_UDPSERVER_HPP

#include <iostream>
#include <string>
#include <boost/array.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>
#include "ANetwork.hpp"

using udp = boost::asio::ip::udp;

namespace Server
{
    class UdpServer  : public ANetwork
    {
    private:
        udp::socket             socket_;
        udp::endpoint           remote_endpoint_;
        char                    recv_buffer_[1024];
    public:
        explicit UdpServer(Mediator &, boost::asio::io_service&);
        virtual ~UdpServer() = default;

        virtual void    receive(Event const &) final;
        void            send(Event event);
    private:
        void    start_receive();
        void    handle_receive(const boost::system::error_code &error, std::size_t bytes_transferred);
        void    handle_send(boost::shared_ptr<std::string>, const boost::system::error_code &, std::size_t /*bytes_transferred*/);
    };
}

#endif //CPP_RTYPE_UDPSERVER_HPP
