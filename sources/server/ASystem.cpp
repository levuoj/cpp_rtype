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
    return (_entities.find(entityName) != _entities.end());
}

AEntity     *ASystem::getEntity(std::string const &entityName) const
{
    auto it = _entities.find(entityName);

    if (it != _entities.end())
        return (it->second.get());
}