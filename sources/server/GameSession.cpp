//
// Created by pashervz on 13/01/18.
//

#include <server/AMap.hpp>
#include <server/EventMap.hpp>
#include <chrono>
#include "server/GameSession.hpp"

void            FF::GameSession::sendMap()
{
    EventMap    event;

    this->getEntity<AMap>(0)->displayMap();
    for (const auto & it : this->getEntity<AMap>(0)->getMap())
    {
        event.mapPacket.insert(Coords<float>(it.first->getX(), it.first->getY()), it.second.first);
    }
    this->_function(event);
}

void            FF::GameSession::initSession()
{
    this->insert<MAP>();
    this->insert<PLAYER>();
    this->insert<BASICMONSTER>();
    this->getEntity<AMap>(0)->putElem((*getEntity<APlayer>(1)->getPositon()), EElement::PLAYER, 1);
    this->getEntity<AMap>(0)->putElem((*getEntity<APlayer>(2)->getPositon()), EElement::BASICMONSTER, 2);
    this->getEntity<APlayer>(1)->setDirection(EMoveType::FORWARD);
    startGame();
}

void            FF::GameSession::update()
{
    for (auto & it : _systems)
    {
        it.second->execute();
    }
}

void            FF::GameSession::loop()
{
    auto                                then = std::chrono::system_clock::now();
    double                              lag = 0.f;
    double                              MS_PER_UPDATE = 0.1f;
    while (_state == RUN)
    {
        auto                            now = std::chrono::system_clock::now();
        std::chrono::duration<double>   elapsed = now - then;
        then = now;
        lag += elapsed.count();

        // GESTION EVENT
        while (lag >= MS_PER_UPDATE)
        {
            update();
            sendMap();
            lag -= MS_PER_UPDATE;
        }
    }
}

void            FF::GameSession::startGame()
{
    _state = RUN;
    this->loop();
}

void            FF::GameSession::stopGame()
{
    _state = STOP;
}

