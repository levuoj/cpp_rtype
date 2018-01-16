//
// Created by pashervz on 13/01/18.
//

#include "server/GameSession.hpp"

void            FF::GameSession::startGame()
{
    _entities.insert(std::make_pair(_entityID, _factory.generate<LEVEL1>()));
    _entities.insert(std::make_pair(_entityID, _factory.generate<PLAYER>()));
    _entities.insert(std::make_pair(_entityID, _factory.generate<MONSTER>()));
}
