//
// Created by pashervz on 13/01/18.
//

#include <server/AMap.hpp>
#include <server/EventMap.hpp>
#include <chrono>
#include "server/GameSession.hpp"

FF::GameSession::GameSession(int id, std::function<void(Event const &)> const & function) : _sessionID(id), _function(function)
{
    _systems["PlayerMovement"] = std::shared_ptr<SMovement>(new SMovement);
    _systems["NonPlayerMovement"] = std::shared_ptr<SMovement>(new SMovement);
//            _systems["PlayerShootMissile"] = std::shared_ptr<SShoot>(new SShoot);
//            _systems["MonsterShootMissile"] = std::shared_ptr<SShoot>(new SShoot);
}

void            FF::GameSession::sendMap()
{
    EventMap    event;

    if (findMap() == -1) {} //ERROR
    this->getEntity<AMap>(findMap())->displayMap();
    for (const auto & it : this->getEntity<AMap>(findMap())->getMap())
        event.mapPacket.insert(Coords<float>(it.first->getX(), it.first->getY()), it.second.first);
    this->_function(event);
}

void            FF::GameSession::putInMap(APlayer *entity)
{
    this->getEntity<AMap>(findMap())->putElem((*entity->getPositon()), EElement::PLAYER, entity->getId());
}

void            FF::GameSession::assignSystems(int id)
{
    switch (_entities[id]->getType())
    {
        case EEntityType::PLAYER:
            _systems.at("PlayerMovement")->addEntity(_entities.at(id), id);
            break;
        case EEntityType::BASICMONSTER:
            _systems.at("NonPlayerMovement")->addEntity(_entities.at(id), id);
            break;
        case EEntityType::MAP:
            std::cout << "sexy star" << std::endl;
            _systems.at("NonPlayerMovement")->addEntity(_entities.at(id), id);
            _systems.at("PlayerMovement")->addEntity(_entities.at(id), id);
//            _systems.at("PlayerShootMissile")->addEntity(_entities.at(id), id);
//            _systems.at("MonsterShootMissile")->addEntity(_entities.at(id), id);
        default:
            break;
    }
}

void            FF::GameSession::initSession()
{
    this->insert<MAP>();
    this->insert<PLAYER>();
    this->insert<BASICMONSTER>();
    this->getEntity<AMap>(0)->putElem((*getEntity<APlayer>(1)->getPosition()), EElement::PLAYER, 1);
    this->getEntity<AMap>(0)->putElem((*getEntity<AMonster>(2)->getPosition()), EElement::BASICMONSTER,
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

void            FF::GameSession::startGame()
{
    _state = RUN;
    this->loop();
}

void            FF::GameSession::stopGame()
{
    _state = STOP;
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

void FF::GameSession::insertMissile()
{
    this->insert<PLAYERMISSILE>();
    this->getEntity<AMap>(0)->putElem((*getEntity<AMissile>(3)->getPosition()), EElement::PLAYERMISSILE, 3);
}
