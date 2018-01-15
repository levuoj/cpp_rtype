//
// Created by Oraekia on 13/01/18.
//

#include <server/Components/CPosition.hpp>
#include <server/Components/CVelocity.hpp>
#include <server/Components/CHealth.hpp>
#include <server/Components/CArtificialIntelligence.hpp>
#include <server/Components/CScore.hpp>
#include <server/Components/CShield.hpp>
#include <server/Components/CExplosion.hpp>
#include "shared_libraries/entities/ETMonster.hpp"

FF::ETMonster::ETMonster() : AMonster()
{
    this->addComponent(std::shared_ptr<AComponent>(new CArtificialIntelligence()));
    this->addComponent(std::shared_ptr<AComponent>(new CPosition()));
    this->addComponent(std::shared_ptr<AComponent>(new CVelocity()));
    this->addComponent(std::shared_ptr<AComponent>(new CHealth()));
    this->addComponent(std::shared_ptr<AComponent>(new CScore()));
    this->addComponent(std::shared_ptr<AComponent>(new CExplosion()));

    this->init();
}

void        FF::ETMonster::init()
{
    reinterpret_cast<CArtificialIntelligence*>(this->getComponent("CAI"))->init();
    reinterpret_cast<CPosition*>(this->getComponent("CPosition"))->setXY(17, 2);
    reinterpret_cast<CVelocity*>(this->getComponent("CVelocity"))->init();
    reinterpret_cast<CHealth*>(this->getComponent("CHealth"))->init();
    reinterpret_cast<CScore*>(this->getComponent("CScore"))->setScore(100);
    reinterpret_cast<CExplosion*>(this->getComponent("CExplosion"))->setPower(1);
}

void FF::ETMonster::move()
{
    reinterpret_cast<CArtificialIntelligence*>(this->getComponent("CAI"))->execute();
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