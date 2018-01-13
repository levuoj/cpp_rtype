//
// Created by Oraekia on 09/01/18.
//

#include <server/ABasicEntity.hpp>
#include <shared_libraries/entities/ETPlayer.hpp>
#include <iostream>
#include <server/Components/CScore.hpp>
#include "server/Components/CHealth.hpp"
#include "server/Components/CPosition.hpp"
#include "server/Components/CVelocity.hpp"

ETPlayer::ETPlayer() : APlayer()
{
    this->addComponent(std::shared_ptr<AComponent>(new CPosition()));
    this->addComponent(std::shared_ptr<AComponent>(new CVelocity()));
    this->addComponent(std::shared_ptr<AComponent>(new CHealth()));
    this->addComponent(std::shared_ptr<AComponent>(new CScore()));

    init();
}

void                ETPlayer::init()
{
    if (this->getComponent("CPosition") != nullptr)
        reinterpret_cast<CPosition*>(this->getComponent("CPosition"))->setXY(15, 2);

    if (this->getComponent("CVelocity") != nullptr)
        reinterpret_cast<CVelocity*>(this->getComponent("CVelocity"))->init();

    if (this->getComponent("CHealth") != nullptr)
        reinterpret_cast<CHealth*>(this->getComponent("CHealth"))->setHealth(3);

    if (this->getComponent("CScore") != nullptr)
        reinterpret_cast<CScore*>(this->getComponent("CScore"))->init();

    std::cout << "I'm a player, TSU" << std::endl;
}

void ETPlayer::move(EMoveType type)
{
    if (this->getComponent("CPosition") != nullptr)
        switch (type)
        {
            case EMoveType::FORWARD:
                reinterpret_cast<CPosition*>(this->getComponent("CPosition"))->moveForward();
            case EMoveType::BACK:
                reinterpret_cast<CPosition*>(this->getComponent("CPosition"))->moveBehind();
            case EMoveType::LEFT:
                reinterpret_cast<CPosition*>(this->getComponent("CPosition"))->moveLeft();
            case EMoveType::RIGHT:
                reinterpret_cast<CPosition*>(this->getComponent("CPosition"))->moveRight();
        }
}

void                ETPlayer::shoot() // A VOIR
{
    std::cout << "let's shoot nigga" << std::endl;
}

void ETPlayer::takeDamage()
{
    if (this->getComponent("CHealth") != nullptr)
        reinterpret_cast<CHealth*>(this->getComponent("CHealth"))->reduceHealth();
}

void ETPlayer::killSomeone(EEntityType type)
{
    switch (type)
    if (this->getComponent("CScore") != nullptr)
        reinterpret_cast<CScore*>(this->getComponent("CScore"))->increase()

}

extern "C"
{
    APlayer         *create()
    {
        return (new ETPlayer());
    }
}