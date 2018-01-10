//
// Created by Oraekia on 10/01/18.
//

#include "server/Components/CHealth.hpp"

CHealth::CHealth() : AComponent("Health"), _health(100) {}

void    CHealth::reduceHealth(int reduce)
{
    if (_health > 0)
        _health -= reduce;
}

void    CHealth::reduceHealth()
{
    if (_health > 0)
        _health--;
}

void CHealth::increaseHealth(int increase)
{
    if (_health < 100)
        _health += increase;
}

void CHealth::increaseHealth()
{
    if (_health < 100)
        _health++;
}

void CHealth::init()
{
    _health = 100;
}
