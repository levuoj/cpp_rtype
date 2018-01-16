//
// Created by Oraekia on 09/01/18.
//

#include <iostream>
#include "shared_libraries/entities/ETPlayer.hpp"

FF::ETPlayer::ETPlayer() : APlayer(), _direction(EMoveType::DEFAULT)
{
    init();
}

void        FF::ETPlayer::init()
{
    reinterpret_cast<CPosition*>(this->getComponent("CPosition"))->setXY(15, 2);
    reinterpret_cast<CVelocity*>(this->getComponent("CVelocity"))->init();
    reinterpret_cast<CHealth*>(this->getComponent("CHealth"))->setHealth(3);
    reinterpret_cast<CScore*>(this->getComponent("CScore"))->init();

    std::cout << "I'm a player, TSU" << std::endl;
}

void          FF::ETPlayer::move()
{
    if (this->getComponent("CPosition") != nullptr && this->getComponent("CVelocity") != nullptr)
    {
        float speed = reinterpret_cast<CVelocity*>(this->getComponent("CVelocity"))->getSpeed();
        switch (_direction)
        {
            case EMoveType::FORWARD:
                reinterpret_cast<CPosition *>(this->getComponent("CPosition"))->moveForward(speed);
                std::cout << "Watashi ga susumemasu. ";
                std::cout << "j'avance" << std::endl;
                break;
            case EMoveType::BACK:
                reinterpret_cast<CPosition *>(this->getComponent("CPosition"))->moveBehind(speed);
                std::cout << "Watashi wa modotte kuru. ";
                std::cout << "Je recule" << std::endl;
                break;
            case EMoveType::LEFT:
                reinterpret_cast<CPosition *>(this->getComponent("CPosition"))->moveLeft(speed);
                std::cout << "Watashi wa hidari ni magaru. ";
                std::cout << "Je tourne à gauche" << std::endl;
                break;
            case EMoveType::RIGHT:
                reinterpret_cast<CPosition *>(this->getComponent("CPosition"))->moveRight(speed);
                std::cout << "Watashi wa migi ni magaru. ";
                std::cout << "Je tourne à droite" << std::endl;
                break;
            default:
                break;
        }
    }
}

void            FF::ETPlayer::takeDamage()
{
        if (reinterpret_cast<CShield *>(this->getComponent("CShield"))->getShield() == 0) {
            reinterpret_cast<CHealth *>(this->getComponent("CHealth"))->reduceHealth();
            std::cout << "Itaidesu, " << reinterpret_cast<CHealth *>(this->getComponent("CHealth"))->getHealt() << std::endl;
        }
        else {
            reinterpret_cast<CShield *>(this->getComponent("CShield"))->takeDamage(1);
            std::cout << "Shīrudo! : " << reinterpret_cast<CShield *>(this->getComponent("CShield"))->getShield() << std::endl;
        }
}

void            FF::ETPlayer::killSomeone(EEntityType type)
{
    if (this->getComponent("CScore") != nullptr) {
        switch (type) {
            case EEntityType::MONSTER:
                reinterpret_cast<CScore *>(this->getComponent("CScore"))->increase(100);
                break;
            case EEntityType::OBSTACLE:
                reinterpret_cast<CScore *>(this->getComponent("CScore"))->increase(50);
                break;
            default:
                break;
        }
        std::cout << "Shi! ";
        std::cout << "Il est mort" << std::endl;
    }
}

void            FF::ETPlayer::takeHealth()
{
    reinterpret_cast<CHealth*>(this->getComponent("CHealth"))->increaseHealth();
    std::cout << "Mugi, men! Hm, des nouilles" << std::endl;
}

void            FF::ETPlayer::takeShield()
{
    if (this->getComponent("CShield") != nullptr)
        reinterpret_cast<CShield*>(this->getComponent("CShield"))->Active();
    else
        reinterpret_cast<CShield*>(this->getComponent("CShield"))->increaseShield();
    std::cout << "Watashi wa tate o sadō sa seru. J'active mon bouclier" << std::endl;
}

extern "C"
{
    FF::APlayer         *create()
    {
        return (new FF::ETPlayer());
    }
}