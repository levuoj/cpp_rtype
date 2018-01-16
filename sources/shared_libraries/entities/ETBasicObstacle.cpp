//
// Created by Oraekia on 16/01/18.
//

#include "shared_libraries/entities/ETBasicObstacle.hpp"

void FF::ETBasicObstacle::move()
{
    float speed = reinterpret_cast<CVelocity*>(this->getComponent("CVelocity"))->getSpeed();
    reinterpret_cast<CPosition*>(this->getComponent("CPosition"))->moveBehind(speed);
}

int FF::ETBasicObstacle::explosion()
{
    return (reinterpret_cast<CExplosion*>(this->getComponent("CExplosion"))->getPower());
}

void FF::ETBasicObstacle::takeDamage(int power)
{
    reinterpret_cast<CHealth*>(this->getComponent("CHealth"))->reduceHealth(power);
}

void FF::ETBasicObstacle::init()
{
    reinterpret_cast<CPosition*>(this->getComponent("CPosition"))->setXY(59, 0);
    reinterpret_cast<CVelocity*>(this->getComponent("CVelocity"))->setSpeed(1);
    reinterpret_cast<CExplosion*>(this->getComponent("CExplosion"))->setPower(1);
    reinterpret_cast<CHealth*>(this->getComponent("CHealth"))->init();
    reinterpret_cast<CScore*>(this->getComponent("CScore"))->setScore(50);
}
