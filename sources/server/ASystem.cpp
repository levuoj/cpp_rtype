//
// Created by pashervz on 09/01/18.
//

#include "server/ASystem.hpp"

void        FF::ASystem::addEntity(std::shared_ptr<AEntity> entity, int id)
{
    _entities.insert(std::make_pair(id, entity));
}

void        FF::ASystem::removeEntity(int id)
{
    if (_entities.find(id) != _entities.end())
        _entities.erase(_entities.find((id)));
}

bool        FF::ASystem::hasEntity(int id) const
{
    return (_entities.find(id) != _entities.end());
}