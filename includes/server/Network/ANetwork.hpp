//
// Created by levuoj on 15/01/18.
//

#ifndef CPP_RTYPE_ANETWORK_HPP
#define CPP_RTYPE_ANETWORK_HPP

#include <utils/AManager.hpp>
#include <server/Network/ProtocolHandler.hpp>


namespace Server
{
    class ANetwork : public AManager
    {
    public:
        ANetwork(Mediator &mediator) : AManager(mediator) {}
        virtual ~ANetwork() = default;
        virtual void receive(Event const &) = 0;
    };
}

#endif //CPP_RTYPE_ANETWORK_HPP
