//
// Created by pashervz on 13/01/18.
//

#include <server/AMap.hpp>
#include "server/GameSession.hpp"

void            FF::GameSession::startGame()
{
    this->insert<MAP>();
    this->insert<PLAYER>();
    this->insert<BASICMONSTER>();
    this->getEntity<AMap>(0)->putElem((*getEntity<APlayer>(1)->getPositon()), EElement::PLAYER, 1);
    this->getEntity<AMap>(0)->putElem((*getEntity<APlayer>(2)->getPositon()), EElement::BASICMONSTER, 2);
    this->getEntity<AMap>(0)->displayMap();
    this->getEntity<APlayer>(1)->setDirection(EMoveType::FORWARD);
    for (auto & it : _systems)
    {
        it.second->execute();
    }
    this->getEntity<AMap>(0)->displayMap();
}

