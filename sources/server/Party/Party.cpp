//
// Created by levuoj on 23/01/18.
//

#include "server/Party/Party.hpp"

Server::Party::Party(size_t id, std::string const &ipAddress) : ID_(id), ID_index(0)
{
    players_.push_back(std::make_shared<Server::Player>(ipAddress, 0));
}

void            Server::Party::addPlayer(std::string const & ipAddress)
{
    players_.push_back(std::make_shared<Server::Player>(ipAddress, players_.size()));
}

void            Server::Party::removePlayer(size_t const& playerID)
{
    players_.erase(players_.begin() + getPlayerIndex(playerID));
}

size_t             Server::Party::getPlayerIndex(size_t const &id) const
{
    size_t index = 0;
    for (auto const& it : players_)
    {
        if (it->getPlayerID() == id)
            return (index);
        index++;
    }
    return (0);
}

size_t const&           Server::Party::getID() const
{
    return (ID_);
}

std::vector<std::shared_ptr<Server::Player>>&    Server::Party::getPlayers()
{
    return (players_);
}
