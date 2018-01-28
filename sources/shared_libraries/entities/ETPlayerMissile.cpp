//
// Created by Oraekia on 16/01/18.
//

#include <server/EEntityType.hpp>
#include "shared_libraries/entities/ETPlayerMissile.hpp"

FF::ETPlayerMissile::ETPlayerMissile() : AMissile(EEntityType::PLAYERMISSILE)
{
    init();
}

FF::CPosition FF::ETPlayerMissile::move()
{
    float speed = reinterpret_cast<CVelocity*>(this->getComponent("CVelocity"))->getSpeed();
    float x = reinterpret_cast<CPosition *>(this->getComponent("CPosition"))->getX();
    float y = reinterpret_cast<CPosition *>(this->getComponent("CPosition"))->getY();

    return (CPosition(x + speed, y));
}

void FF::ETPlayerMissile::init()
{
    reinterpret_cast<CVelocity *>(this->getComponent("CVelocity"))->setSpeed(1);
    reinterpret_cast<CPosition *>(this->getComponent("CPosition"))->init();
}

int    FF::ETPlayerMissile::explosion()
{
    reinterpret_cast<CExplosion *>(this->getComponent("CExplosion"))->setPower(100);
    return (reinterpret_cast<CExplosion *>(this->getComponent("CExplosion"))->getPower());
}

extern "C"
{
    FF::AMissile         *create()
    {
        return (new FF::ETPlayerMissile());
    }
}
