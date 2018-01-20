//
// Created by Oraekia on 09/01/18.
//

#include <iostream>
#include "shared_libraries/entities/ETPlayer.hpp"

FF::ETPlayer::ETPlayer() : APlayer(EEntityType::PLAYER), _direction(EMoveType::FORWARD)
{
    init();
}

void        FF::ETPlayer::init()
{
    reinterpret_cast<CPosition*>(this->getComponent("CPosition"))->setXY(15, 2);
    reinterpret_cast<CVelocity*>(this->getComponent("CVelocity"))->init();
    reinterpret_cast<CHealth*>(this->getComponent("CHealth"))->setHealth(3);
    reinterpret_cast<CScore*>(this->getComponent("CScore"))->init();
}

FF::CPosition       FF::ETPlayer::move()
{
    if (this->getComponent("CPosition") != nullptr && this->getComponent("CVelocity") != nullptr)
    {
        float x = reinterpret_cast<CPosition *>(this->getComponent("CPosition"))->getX();
        float y = reinterpret_cast<CPosition *>(this->getComponent("CPosition"))->getY();
        float speed = reinterpret_cast<CVelocity*>(this->getComponent("CVelocity"))->getSpeed();
        switch (_direction)
        {
            case EMoveType::FORWARD:
                return (CPosition(x + speed, y));
            case EMoveType::BACK:
                return (CPosition(x - speed, y));
            case EMoveType::LEFT:
                return (CPosition(x, y + speed));
            case EMoveType::RIGHT:
                return (CPosition(x, y - speed));
            default:
                break;
        }
    }
    return (CPosition(0, 0));
}

void            FF::ETPlayer::takeDamage()
{
        if (reinterpret_cast<CShield *>(this->getComponent("CShield"))->getShield() == 0) {
            reinterpret_cast<CHealth *>(this->getComponent("CHealth"))->reduceHealth();;
        }
        else
            reinterpret_cast<CShield *>(this->getComponent("CShield"))->takeDamage(1);
}

void            FF::ETPlayer::killSomeone(EEntityType type)
{
    if (this->getComponent("CScore") != nullptr) {
        switch (type) {
            case EEntityType::BASICMONSTER:
                reinterpret_cast<CScore *>(this->getComponent("CScore"))->increase(100);
                break;
            case EEntityType::BASICOBSTACLE:
                reinterpret_cast<CScore *>(this->getComponent("CScore"))->increase(50);
                break;
            default:
                break;
        }
    }
}

void            FF::ETPlayer::takeHealth()
{
    reinterpret_cast<CHealth*>(this->getComponent("CHealth"))->increaseHealth();
}

void            FF::ETPlayer::takeShield()
{
    if (this->getComponent("CShield") != nullptr)
        reinterpret_cast<CShield*>(this->getComponent("CShield"))->Active();
    else
        reinterpret_cast<CShield*>(this->getComponent("CShield"))->increaseShield();
}

extern "C"
{
    FF::APlayer         *create()
    {
        return (new FF::ETPlayer());
    }
}