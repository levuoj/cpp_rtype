//
// Created by Oraekia on 13/01/18.
//

#include <iostream>
#include "shared_libraries/entities/ETMonster.hpp"

FF::ETMonster::ETMonster() : AMonster(EEntityType::MONSTER)
{
    this->init();
}

void        FF::ETMonster::init()
{
    reinterpret_cast<CArtificialIntelligence*>(this->getComponent("CAI"))->init();
    reinterpret_cast<CPosition*>(this->getComponent("CPosition"))->setXY(55, 10);
    reinterpret_cast<CVelocity*>(this->getComponent("CVelocity"))->init();
    reinterpret_cast<CHealth*>(this->getComponent("CHealth"))->init();
    reinterpret_cast<CScore*>(this->getComponent("CScore"))->setScore(100);
    reinterpret_cast<CExplosion*>(this->getComponent("CExplosion"))->setPower(1);

    std::cout << "BLOUEEEEERG" << std::endl;
}

FF::CPosition FF::ETMonster::move()
{
    float x = reinterpret_cast<CPosition *>(this->getComponent("CPosition"))->getX();
    float y = reinterpret_cast<CPosition *>(this->getComponent("CPosition"))->getY();

    return (CPosition(x - 1, y));
}

void FF::ETMonster::takeDamage(int power)
{
    reinterpret_cast<CHealth*>(this->getComponent("CHealth"))->reduceHealth(power);
}

void FF::ETMonster::takeHealth()
{
    reinterpret_cast<CHealth*>(this->getComponent("CHealth"))->increaseHealth();
}

int FF::ETMonster::scoreOfDie()
{
    return(reinterpret_cast<CScore*>(this->getComponent("CScore"))->getScore());
}

int FF::ETMonster::explosion()
{
    return (reinterpret_cast<CExplosion*>(this->getComponent("CExplosion"))->getPower());
}

extern "C"
{
    FF::AMonster        *create()
    {
        return (new FF::ETMonster());
    }
}