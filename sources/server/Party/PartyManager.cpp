//
// Created by levuoj on 23/01/18.
//

#include "server/Party/PartyManager.hpp"

std::vector<std::shared_ptr<Server::Party>>&    Server::PartyManager::getParties()
{
    return (parties_);
}

void    Server::PartyManager::addParty(std::string const & ipAddress)
{
    parties_.push_back(std::make_shared<Server::Party>(parties_.size(), ipAddress));
}

void    Server::PartyManager::removeParty(size_t const &idParty)
{
    parties_.erase(parties_.begin() + getPartyIndex(idParty));
}

size_t          Server::PartyManager::getPartyIndex(size_t const &idParty) const
{
    size_t index = 0;
    for (auto const &it : parties_)
    {
        if (it->getID() == idParty)
            return (index);
        index++;
    }
    return (0);
}

void           Server::PartyManager::receive(Event const & event)
{
    switch (event.type)
    {
        case EventType::NEWGAME :
            createParty(event);
            break;
        case EventType::JOINGAME :
            joinParty(event);
            break;
        case EventType::INPUT :
            sendInput(event);
            break;
        default:
            break;
    }
}

void            Server::PartyManager::createParty(Event const & event)
{
    addParty(event.datas.back());
}

void            Server::PartyManager::joinParty(Event const& event)
{
    for (auto const& it : parties_)
    {
        if (it.get()->getPlayers().front().get()->getIpAddress() == event.datas.front())
            it.get()->addPlayer(event.datas.back());
    }
}

void            Server::PartyManager::sendInput(Event const&)
{}