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
#include "utils/AManager.hpp"

using udp = boost::asio::ip::udp;

namespace Server
{
    class UdpServer  : public AManager
    {
    private:
        boost::asio::io_service io_service_;
        udp::socket             socket_;
        udp::endpoint           remote_endpoint_;
        char                    recv_buffer_[1024];
    public:
        explicit UdpServer(Mediator &);
        virtual ~UdpServer() = default;

        virtual void    receive(Event const &) final;
        virtual void    sending(udp::endpoint const& ep) final;
        virtual void    launch() final;
    private:
        void    start_receive();
        void    handle_receive(const boost::system::error_code &error, std::size_t bytes_transferred);
        void    handle_send(boost::shared_ptr<std::string>, const boost::system::error_code &, std::size_t /*bytes_transferred*/);
    };
}

#endif //CPP_RTYPE_UDPSERVER_HPP
