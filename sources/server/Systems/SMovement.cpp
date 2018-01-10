//
// Created by pashervz on 09/01/18.
//

#include "server/Systems/SMovement.hpp"

SMovement::SMovement() : ASystem("Movement")
{
}

void            SMovement::execute()
{
    for (const auto & itET : _entities)
    {
        if (itET.second->getComponent("Position") != nullptr)
            itET.second->getComponent("Position")->update();
        if (itET.second->getComponent("Velocity") != nullptr)
            itET.second->getComponent("Velocity")->update();
    }
}