//
// Created by levuoj on 23/01/18.
//

#include "server/Party/PartyManager.hpp"

void                    Server::PartyManager::receive(Event const &)
{
}

std::vector<Party>&     Server::PartyManager::getParties() const
{
    return (parties_);
}