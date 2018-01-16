//
// Created by Oraekia on 10/01/18.
//

#include <iostream>
#include "server/Components/CShield.hpp"

FF::CShield::CShield() : AComponent("Shield"), _healthOfShield(0), _isActivate(false) {}

FF::CShield::CShield(int health) : AComponent("Shield"), _healthOfShield(health), _isActivate(true){}

void        FF::CShield::takeDamage(int power)
{
    if (_healthOfShield > 0 && _isActivate)
        _healthOfShield -= power;
    if (_healthOfShield == 0 && _isActivate)
        this->Disable();
}

void        FF::CShield::regeneration(int regen)
{
    if (_healthOfShield < 100 && _isActivate)
        _healthOfShield += regen;
}

void        FF::CShield::Disable() {
    if (_isActivate)
        _isActivate = false;
}

void        FF::CShield::Active()
{
    if (!_isActivate)
        _isActivate = true;
}

void        FF::CShield::init()
{
    _healthOfShield = 100;
    _isActivate = true;
}