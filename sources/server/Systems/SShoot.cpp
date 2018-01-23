//
// Created by Oraekia on 17/01/18.
//

#include <server/APlayer.hpp>
#include <iostream>
#include "server/Systems/SShoot.hpp"

FF::SShoot::SShoot() : ASystem("Shoot") {}

void FF::SShoot::execute()
{
    for (const auto &itET : _entities)
    {
        if (itET.second->getType() == EEntityType::PLAYER)
        {
            CPosition pos = *reinterpret_cast<APlayer *>(itET.second.get())->getPosition();
            pos.setX(pos.getX() + 0.5f);
            if (this->getMap()->doShifting(itET.second.get()->getId(), EElement::PLAYERMISSILE, pos))
                _callback(EEntityType::PLAYERMISSILE);
        }
    }
}
