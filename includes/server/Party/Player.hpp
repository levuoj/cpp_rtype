//
// Created by levuoj on 21/01/18.
//

#ifndef CPP_RTYPE_PLAYER_HPP
#define CPP_RTYPE_PLAYER_HPP

#include <string>

namespace Server
{
    class Player
    {
    private:
        std::string     ip_address_;
        size_t          ID_;
    public:
        Player(std::string const& ipAddress, size_t id);
        ~Player() = default;

        std::string const& getIpAddress() const;
        size_t const&      getPlayerID() const;
    };
}

#endif //CPP_RTYPE_PLAYER_HPP
