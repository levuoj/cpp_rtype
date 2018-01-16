//
// Created by Oraekia on 09/01/18.
//

#include <iostream>
#include <server/Components/CShield.hpp>
#include "shared_libraries/entities/ETPlayer.hpp"
#include "server/Components/CScore.hpp"
#include "server/Components/CHealth.hpp"
#include "server/Components/CPosition.hpp"
#include "server/Components/CVelocity.hpp"

FF::ETPlayer::ETPlayer() : APlayer()
{
    this->addComponent(std::shared_ptr<AComponent>(new CPosition()));
    this->addComponent(std::shared_ptr<AComponent>(new CVelocity()));
    this->addComponent(std::shared_ptr<AComponent>(new CHealth()));
    this->addComponent(std::shared_ptr<AComponent>(new CScore()));

    init();
}

void        FF::ETPlayer::init()
{
    if (this->getComponent("Position") != nullptr)
        reinterpret_cast<CPosition*>(this->getComponent("Position"))->setXY(15, 2);

    if (this->getComponent("CVelocity") != nullptr)
        reinterpret_cast<CVelocity*>(this->getComponent("Velocity"))->init();

    if (this->getComponent("CHealth") != nullptr)
        reinterpret_cast<CHealth*>(this->getComponent("Health"))->setHealth(3);

    if (this->getComponent("Score") != nullptr)
        reinterpret_cast<CScore*>(this->getComponent("Score"))->init();

    std::cout << "I'm a player, TSU" << std::endl;
}

void          FF::ETPlayer::move(EMoveType type)
{
    if (this->getComponent("Position") != nullptr && this->getComponent("Velocity") != nullptr)
    {
        float speed = reinterpret_cast<CVelocity*>(this->getComponent("Velocity"))->getSpeed();
        switch (type)
        {
            case EMoveType::FORWARD:
                reinterpret_cast<CPosition *>(this->getComponent("Position"))->moveForward(speed);
                break;
            case EMoveType::BACK:
                reinterpret_cast<CPosition *>(this->getComponent("Position"))->moveBehind(speed);
                break;
            case EMoveType::LEFT:
                reinterpret_cast<CPosition *>(this->getComponent("Position"))->moveLeft(speed);
                break;
            case EMoveType::RIGHT:
                reinterpret_cast<CPosition *>(this->getComponent("Position"))->moveRight(speed);
                break;
        }
    }
}

void            FF::ETPlayer::takeDamage()
{
    if (this->getComponent("Health") != nullptr) {
        if (reinterpret_cast<CShield *>(this->getComponent("Shield"))->getShield() == 0)
            reinterpret_cast<CHealth *>(this->getComponent("Health"))->reduceHealth();
        else {
            reinterpret_cast<CShield *>(this->getComponent("Shield"))->takeDamage(1);
            if (reinterpret_cast<CShield *>(this->getComponent("Shield"))->getShield() == 0)
                this->removeComponent("Shield");
        }
    }
}

void            FF::ETPlayer::killSomeone(EEntityType type)
{
    if (this->getComponent("Score") != nullptr) {
        switch (type) {
            case EEntityType::MONSTER:
                reinterpret_cast<CScore *>(this->getComponent("Score"))->increase(100);
                break;
            case EEntityType::OBSTACLE:
                reinterpret_cast<CScore *>(this->getComponent("Score"))->increase(50);
                break;
            default:
                break;
        }
    }
}

void            FF::ETPlayer::takeHealth()
{
    if (this->getComponent("Health") != nullptr)
        reinterpret_cast<CHealth*>(this->getComponent("Health"))->increaseHealth();
}

void            FF::ETPlayer::takeShield()
{
    if (this->getComponent("Shield") == nullptr)
        this->addComponent(std::shared_ptr<AComponent>(new CShield(1)));
    else
        reinterpret_cast<CShield*>(this->getComponent("Shield"))->increaseShield();
}

extern "C"
{
    FF::APlayer         *create()
    {
        return (new FF::ETPlayer());
    }
}