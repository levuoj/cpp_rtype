//
// Created by levuoj on 21/01/18.
//

#ifndef CPP_RTYPE_PARTY_HPP
#define CPP_RTYPE_PARTY_HPP

#include <memory>
#include <vector>
#include "Player.hpp"

namespace Server
{
    class Party
    {
    private:
        std::vector<std::shared_ptr<Player>>    players_;
        size_t                                  ID_;
        size_t                                  ID_index;
    public:
        Party(size_t id, std::string const& ipAddress);
        ~Party() = default;

        size_t const&           getID() const;
        std::vector<std::shared_ptr<Player>>&   getPlayers();
        void                                    addPlayer(std::string const& ipAddress);
        void                                    removePlayer(size_t const& playerID);
        size_t                                  getPlayerIndex(size_t const& id) const;
    };
}

#endif //CPP_RTYPE_PARTY_HPP
