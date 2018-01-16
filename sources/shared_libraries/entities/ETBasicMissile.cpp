//
// Created by Oraekia on 16/01/18.
//

#include <server/EEntityType.hpp>
#include "shared_libraries/entities/ETBasicMissile.hpp"

FF::ETBasicMissile::ETBasicMissile() : AMissile(EEntityType::BASICMISSILE)
{
    init();
}

FF::CPosition FF::ETBasicMissile::move()
{
    float speed = reinterpret_cast<CVelocity*>(this->getComponent("CVelocity"))->getSpeed();
    float x = reinterpret_cast<CPosition *>(this->getComponent("CPosition"))->getX();
    float y = reinterpret_cast<CPosition *>(this->getComponent("CPosition"))->getY();

    return (CPosition(x + speed, y));
}

void FF::ETBasicMissile::init()
{
    reinterpret_cast<CVelocity *>(this->getComponent("CVelocity"))->setSpeed(1);
    reinterpret_cast<CPosition *>(this->getComponent("CPosition"))->init();
}

int    FF::ETBasicMissile::explosion()
{
    reinterpret_cast<CExplosion *>(this->getComponent("CExplosion"))->setPower(100);
    return (reinterpret_cast<CExplosion *>(this->getComponent("CExplosion"))->getPower());
}
