//
// Created by pashervz on 09/01/18.
//

#include "server/ASystem.hpp"

void        FF::ASystem::addEntity(AEntity &entity)
{
    _entities.insert(std::make_pair(entity.getName(), std::unique_ptr<AEntity>(&entity)));
}

void        FF::ASystem::removeEntity(std::string const & entityName)
{
    if (_entities.find(entityName) != _entities.end())
        _entities.erase(_entities.find((entityName)));
}

bool        FF::ASystem::hasEntity(std::string const & entityName) const
{
    return (_entities.find(entityName) != _entities.end());
}

FF::AEntity     *FF::ASystem::getEntity(std::string const &entityName) const
{
    auto it = _entities.find(entityName);

    if (it != _entities.end())
        return (it->second.get());
    return (nullptr);
}