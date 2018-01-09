//
// Created by pashervz on 09/01/18.
//

#include "server/ASystem.hpp"

void        ASystem::addEntity(AEntity &entity)
{
    _entities.insert(std::make_pair(entity.getName(), std::unique_ptr<AEntity>(&entity)));
}

void        ASystem::removeEntity(std::string const & entityName)
{
    if (_entities.find(entityName) != _entities.end())
        _entities.erase(_entities.find((entityName)));
}

bool        ASystem::hasEntity(std::string const & entityName) const
{
    if (_entities.find(entityName) != _entities.end())
        return true;
    return false;
}
