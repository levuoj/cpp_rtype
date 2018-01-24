//
// Created by pashervz on 13/01/18.
//

#include <server/AMap.hpp>
#include <server/EventMap.hpp>
#include <chrono>
#include <utils/Error.hpp>
#include <server/Systems/SSpawn.hpp>
#include <server/AMissile.hpp>
#include "server/GameSession.hpp"

FF::GameSession::GameSession(int id, std::function<void(Event const &)> const & function) : _sessionID(id),
                                                                                            _function(function)
{
    _actionManager.addSystem("PlayerMovement", std::shared_ptr<SMovement>(new SMovement));
    _systems["NonPlayerMovement"] = std::shared_ptr<SMovement>(new SMovement);
}

void            FF::GameSession::sendMap()
{
    EventMap    event;

    if (findMap() == -1)
        throw Error("No Map");
    this->getEntity<AMap>(findMap())->displayMap();
    for (const auto & it : this->getEntity<AMap>(findMap())->getMap())
        event.mapPacket.insert(Coords<float>(it.first->getX(), it.first->getY()), it.second);
    this->_function(event);
}

void            FF::GameSession::putInMap(APlayer *entity)
{

    this->getEntity<AMap>(findMap())->putElem((*entity->getPosition()), MapElem(EElement::PLAYER, entity->getId()));
}

void            FF::GameSession::putInMap(AMonster *entity)
{
    this->getEntity<AMap>(findMap())->putElem((*entity->getPositon()), MapElem(EElement::BASICMONSTER, entity->getId()));
}

void            FF::GameSession::putInMap(AMissile *entity)
{
  this->getEntity<AMap>(findMap())->putElem((*entity->getPosition()), MapElem(EElement::PLAYERMISSILE, entity->getId()));
}

void            FF::GameSession::assignSystems(int id)
{
    switch (_entities[id]->getType())
    {
        case EEntityType::PLAYER1:
            _actionManager.assign("PlayerMovement", _entities.at(id), id);
            break;
        case EEntityType::PLAYER2:
            _actionManager.assign("PlayerMovement", _entities.at(id), id);
            break;
        case EEntityType::PLAYER3:
            _actionManager.assign("PlayerMovement", _entities.at(id), id);
            break;
        case EEntityType::PLAYER4:
            _actionManager.assign("PlayerMovement", _entities.at(id), id);
            break;
        case EEntityType::BASICMONSTER:
            _systems.at("NonPlayerMovement")->addEntity(_entities.at(id), id);
            break;
        case EEntityType::PLAYERMISSILE:
            _systems.at("PlayerShootMissile")->addEntity(_entities.at(id), id);
            break;
        case EEntityType::MAP:
            _systems.at("NonPlayerMovement")->addEntity(_entities.at(id), id);
            _actionManager.assign("PlayerMovement", _entities.at(id), id);
        default:
            break;
    }
}

void            FF::GameSession::initSession()
{
    _systems["Spawn"] = std::shared_ptr<SSpawn>(new SSpawn([this](EEntityType type) { insert(type); },
                                                           EEntityType::NOTHING));
    _systems["Shoot"] = std::shared_ptr<SShoot>(new SShoot([this](EEntityType type) { insert(type); },
                                                           EEntityType::PLAYERMISSILE));
    this->insert(EEntityType::MAP);
    startGame();
}

void            FF::GameSession::update()
{
    for (auto & it : _systems)
    {
        if (it.first != "Spawn")
            it.second->execute();
    }
}

void            FF::GameSession::startGame()
{
    _state = RUN;
    reinterpret_cast<SSpawn *>(_systems.at("Spawn").get())->setType(EEntityType::PLAYER);
    _systems.at("Spawn")->execute();
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
    while (_state != STOP)
    {
        auto                            now = std::chrono::system_clock::now();

        std::chrono::duration<double>   elapsed = now - then;
        then = now;
        lag += elapsed.count();

//        _actionManager.doAction(_eventManager.treat());
        while (lag >= MS_PER_UPDATE)
        {
            update();
            sendMap();
            lag -= MS_PER_UPDATE;
        }
    }
}

void                FF::GameSession::insert(EEntityType type) {
    if ((_entities[_entityID] = _factory.generate(type)) == nullptr)
        return ;
    _entities.at(_entityID).get()->setId(_entityID);
    assignSystems(_entityID);
    if (findMap() != -1) {
        switch (type)
        {
            case EEntityType::PLAYER:
                putInMap(reinterpret_cast<APlayer *>(_entities[_entityID].get()));
                break;
            case EEntityType::BASICMONSTER:
                putInMap(reinterpret_cast<AMonster *>(_entities[_entityID].get()));
                break;
            default:
                break;
        }
    }
    _entityID++;
}
