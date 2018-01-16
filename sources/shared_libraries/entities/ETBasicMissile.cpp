//
// Created by Oraekia on 16/01/18.
//

#include <server/EEntityType.hpp>
#include "shared_libraries/entities/ETBasicMissile.hpp"

FF::ETBasicMissile::ETBasicMissile() : _typeOfLauncher(EEntityType::NOTHING)
{
    init();
}

void FF::ETBasicMissile::move()
{
    float speed = reinterpret_cast<CVelocity *>(this->getComponent("CVelocity"))->getSpeed();
    if (_typeOfLauncher == EEntityType::PLAYER)
        reinterpret_cast<CPosition *>(this->getComponent("CPosition"))->moveForward(speed);
    else
        reinterpret_cast<CPosition *>(this->getComponent("CPosition"))->moveBehind(speed);
}

void FF::ETBasicMissile::init()
{
    reinterpret_cast<CVelocity *>(this->getComponent("CVelocity"))->setSpeed(1);
    reinterpret_cast<CPosition *>(this->getComponent("CPosition"))->init();
}

int    FF::ETBasicMissile::explosion()
{
    if (_typeOfLauncher == EEntityType::PLAYER)
    {
        reinterpret_cast<CExplosion *>(this->getComponent("CExplosion"))->setPower(100);
        return (reinterpret_cast<CExplosion *>(this->getComponent("CExplosion"))->getPower());
    }
    else
    {
        reinterpret_cast<CExplosion *>(this->getComponent("CExplosion"))->setPower(1);
        return (reinterpret_cast<CExplosion *>(this->getComponent("CExplosion"))->getPower());
    }

}
