//
// Created by Oraekia on 13/01/18.
//

#include <iostream>
#include "shared_libraries/entities/ETBasicMonster.hpp"

FF::ETBasicMonster::ETBasicMonster() : AMonster(EEntityType::BASICMONSTER)
{
    this->init();
}

void        FF::ETBasicMonster::init()
{
    reinterpret_cast<CArtificialIntelligence*>(this->getComponent("CAI"))->init();
    reinterpret_cast<CPosition*>(this->getComponent("CPosition"))->setXY(55, 10);
    reinterpret_cast<CVelocity*>(this->getComponent("CVelocity"))->init();
    reinterpret_cast<CHealth*>(this->getComponent("CHealth"))->init();
    reinterpret_cast<CScore*>(this->getComponent("CScore"))->setScore(100);
    reinterpret_cast<CExplosion*>(this->getComponent("CExplosion"))->setPower(1);

    std::cout << "BLOUEEEEERG" << std::endl;
}

FF::CPosition   FF::ETBasicMonster::move()
{
    float x = reinterpret_cast<CPosition *>(this->getComponent("CPosition"))->getX();
    float y = reinterpret_cast<CPosition *>(this->getComponent("CPosition"))->getY();
    float speed = reinterpret_cast<CVelocity*>(this->getComponent("CVelocity"))->getSpeed();

    return (CPosition(x - speed, y));
}

void FF::ETBasicMonster::takeDamage(int power)
{
    reinterpret_cast<CHealth*>(this->getComponent("CHealth"))->reduceHealth(power);
}

void FF::ETBasicMonster::takeHealth()
{
    reinterpret_cast<CHealth*>(this->getComponent("CHealth"))->increaseHealth();
}

int FF::ETBasicMonster::scoreOfDie()
{
    return(reinterpret_cast<CScore*>(this->getComponent("CScore"))->getScore());
}

int FF::ETBasicMonster::explosion()
{
    return (reinterpret_cast<CExplosion*>(this->getComponent("CExplosion"))->getPower());
}

extern "C"
{
    FF::AMonster        *create()
    {
        return (new FF::ETBasicMonster());
    }
}