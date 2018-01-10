//
// Created by levuoj on 10/01/18.
//

#ifndef CPP_RTYPE_UDPBOOSTNETWORK_HPP
#define CPP_RTYPE_UDPBOOSTNETWORK_HPP

#include <string>
#include <boost/array.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>
#include "IUDPNetwork.hpp"

class UDPBoostNetwork : public IUDPNetwork
{
    using udp = boost::asio::ip::udp;
private:
    udp::socket   socket_;
    udp::endpoint remote_endpoint_;
    boost::array<char, 1> recv_buffer_;
public:
    virtual void();
};


#endif //CPP_RTYPE_UDPBOOSTNETWORK_HPP
