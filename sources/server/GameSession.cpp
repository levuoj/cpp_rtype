//
// Created by pashervz on 13/01/18.
//

#include <server/AMap.hpp>
#include <server/EventMap.hpp>
#include <server/AMonster.hpp>
#include <server/AMissile.hpp>
#include "server/GameSession.hpp"

void            FF::GameSession::sendMap()
{
    EventMap    event;

    for (const auto & it : this->getEntity<AMap>(0)->getMap())
    {
        event.mapPacket.insert(Coords<float>(it.first.get()->getX(), it.first.get()->getY()), it.second.first);
    }
    this->_function(event);
}

void            FF::GameSession::startGame()
{
    this->insert<MAP>();
    this->insert<PLAYER>();
    this->insert<BASICMONSTER>();
    this->getEntity<AMap>(0)->putElem((*getEntity<APlayer>(1)->getPosition()), EElement::PLAYER, 1);
    this->getEntity<AMap>(0)->putElem((*getEntity<AMonster>(2)->getPosition()), EElement::BASICMONSTER, 2);
    this->getEntity<AMap>(0)->displayMap();
    this->getEntity<APlayer>(1)->setDirection(EMoveType::FORWARD);
    for (auto & it : _systems)
    {
        it.second->execute();
    }
    this->getEntity<AMap>(0)->displayMap();
    this->sendMap();
}

void FF::GameSession::insertMissile()
{
    this->insert<PLAYERMISSILE>();
    this->getEntity<AMap>(0)->putElem((*getEntity<AMissile>(3)->getPosition()), EElement::PLAYERMISSILE, 3);
}
