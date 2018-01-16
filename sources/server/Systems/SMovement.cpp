//
// Created by pashervz on 09/01/18.
//

#include "server/Systems/SMovement.hpp"

FF::SMovement::SMovement() : ASystem("Movement")
{
}

void            FF::SMovement::execute()
{
    for (const auto & itET : _entities)
    {
        if (itET.second->getComponent("Position") != nullptr)
            itET.second->getComponent("Position")->init();
        if (itET.second->getComponent("Velocity") != nullptr)
            itET.second->getComponent("Velocity")->init();
    }
}