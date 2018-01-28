//
// Created by pashervz on 20/01/18.
//

#include "server/Systems/SSpawn.hpp"

FF::SSpawn::SSpawn(std::function<void(EEntityType)> const &function, EEntityType type) : ASystem("Spawn"),
                                                                                         _function(std::move(function)),
                                                                                         _type(type) {}

void            FF::SSpawn::execute()
{
    if (_type != NOTHING)
        _function(_type);
}