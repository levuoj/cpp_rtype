//
// Created by levuoj on 28/01/18.
//

#ifndef CPP_RTYPE_IUDPSOCKET_HPP
#define CPP_RTYPE_IUDPSOCKET_HPP

#include "utils/Event.hpp"

namespace Server
{
    class IUDPSocket
    {
    public:
        virtual ~IUDPSocket() = default;
        virtual void    start_receive() = 0;
        virtual void    send(Event const& event) = 0;
    };
}
#endif //CPP_RTYPE_IUDPSOCKET_HPP
