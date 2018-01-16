//
// Created by Oraekia on 10/01/18.
//

#include "server/Components/CHealth.hpp"

FF::CHealth::CHealth() : AComponent("Health"), _health(100) {}

void    FF::CHealth::reduceHealth(int reduce)
{
    if (_health > 0)
        _health -= reduce;
}

void    FF::CHealth::reduceHealth()
{
    if (_health > 0)
        _health--;
}

void    FF::CHealth::increaseHealth(int increase)
{
    if (_health < 100)
        _health += increase;
}

void    FF::CHealth::increaseHealth()
{
    if (_health < 100)
        _health++;
}

void    FF::CHealth::init()
{
    _health = 100;
}
