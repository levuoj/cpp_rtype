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
        std::vector<Player>     players_;
        size_t                  ID_;
    public:
        Party(size_t id);
        ~Party(){}

        size_t const&           getID() const;
        std::vector<Player>&    getPlayers() const;
        void                    addPlayer(std::string const& ipAddress, size_t );
        void                    removePlayer(size_t playerID);
    };
}

#endif //CPP_RTYPE_PARTY_HPP
