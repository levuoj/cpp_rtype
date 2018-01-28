//
// Created by levuoj on 21/01/18.
//

#ifndef CPP_RTYPE_PARTYMANAGER_HPP
#define CPP_RTYPE_PARTYMANAGER_HPP

#include <vector>
#include <memory>
#include "utils/AManager.hpp"
#include "server/Party/Party.hpp"

namespace Server
{
    class                   PartyManager : public AManager
    {
    private:
        size_t                                  party_id;
        std::vector<std::shared_ptr<Party>>     parties_;

        void                createParty(Event const& event);
        void                joinParty(const Event &event);
        void                sendInput(Event const& event);
    public:
        explicit PartyManager(Mediator &mediator) : AManager(mediator), party_id(0) {}
        ~PartyManager() override = default;
        void receive(Event const&) final;

        std::vector<std::shared_ptr<Party>>&    getParties();
        void                                    addParty(std::string const& ipAddress);
        void                                    removeParty(size_t const& idParty);
        size_t                                  getPartyIndex(size_t const& idParty) const;
    };
}

#endif //CPP_RTYPE_PARTYMANAGER_HPP
