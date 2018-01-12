//
// Created by Oraekia on 09/01/18.
//

#include <server/AEntity.hpp>
#include <shared_libraries/entities/ETPlayer.hpp>
#include <iostream>
#include "server/Components/CPosition.hpp"
#include "server/Components/CVelocity.hpp"

ETPlayer::ETPlayer() : AEntity("Player")
{
    this->addComponent(std::shared_ptr<AComponent>(new CPosition()));
    this->addComponent(std::shared_ptr<AComponent>(new CVelocity()));
}

void                ETPlayer::init()
{
    if (this->getComponent("CPosition") != nullptr)
        dynamic_cast<CPosition*>(this->getComponent("CPosition"))->setXY(15, 2);

    if (this->getComponent("CVelocity") != nullptr)
        dynamic_cast<CPosition*>(this->getComponent("CVelocity"))->init();
}

void                ETPlayer::shoot()
{
    std::cout << "let's shoot nigga" << std::endl;
}

extern "C"
{
    AEntity         *create()
    {
        return (new ETPlayer());
    }
}