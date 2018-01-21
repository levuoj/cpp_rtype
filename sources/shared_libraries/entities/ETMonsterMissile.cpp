//
// Created by Oraekia on 16/01/18.
//

#include <server/EEntityType.hpp>
#include <shared_libraries/entities/ETMonsterMissile.hpp>

FF::ETMonsterMissile::ETMonsterMissile() : AMissile(EEntityType::PLAYERMISSILE)
{
    init();
}

FF::CPosition FF::ETMonsterMissile::move()
{
    float speed = reinterpret_cast<CVelocity*>(this->getComponent("CVelocity"))->getSpeed();
    float x = reinterpret_cast<CPosition *>(this->getComponent("CPosition"))->getX();
    float y = reinterpret_cast<CPosition *>(this->getComponent("CPosition"))->getY();

    return (CPosition(x - speed, y));
}

void FF::ETMonsterMissile::init()
{
    reinterpret_cast<CVelocity *>(this->getComponent("CVelocity"))->setSpeed(1);
    reinterpret_cast<CPosition *>(this->getComponent("CPosition"))->init();
}

int    FF::ETMonsterMissile::explosion()
{
    reinterpret_cast<CExplosion *>(this->getComponent("CExplosion"))->setPower(1);
    return (reinterpret_cast<CExplosion *>(this->getComponent("CExplosion"))->getPower());
}

extern "C"
{
    FF::AMissile         *create()
    {
        return (new FF::ETMonsterMissile());
    }
}
