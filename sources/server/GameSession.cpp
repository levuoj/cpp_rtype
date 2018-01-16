//
// Created by pashervz on 13/01/18.
//

#include <server/AMap.hpp>
#include "server/GameSession.hpp"

void            FF::GameSession::startGame()
{
    this->insert<LEVEL1>();
    this->insert<PLAYER>();
    this->insert<MONSTER>();
    this->getEntity<AMap>(0)->putElem((*getEntity<APlayer>(1)->getPositon()), EElement::PLAYER);
    this->getEntity<AMap>(0)->putElem((*getEntity<APlayer>(2)->getPositon()), EElement::MONSTER);
    this->getEntity<AMap>(0)->displayMap();
}

