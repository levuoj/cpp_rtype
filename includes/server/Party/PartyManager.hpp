//
// Created by levuoj on 21/01/18.
//

#ifndef CPP_RTYPE_PARTYMANAGER_HPP
#define CPP_RTYPE_PARTYMANAGER_HPP

#include <vector>
#include "utils/AManager.hpp"
#include "Party.hpp"

namespace Server
{
    class                   PartyManager : public AManager
    {
    private:
        std::vector<Party>  parties_;
    public:
        PartyManager(Mediator &mediator) : AManager(mediator) {}
        virtual ~PartyManager() = default;
        void receive(Event const&);

        std::vector<Party>& getParties() const;
    };
}

#endif //CPP_RTYPE_PARTYMANAGER_HPP
