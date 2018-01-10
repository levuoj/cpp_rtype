//
// Created by Oraekia on 10/01/18.
//

#include <iostream>
#include "server/Components/CShield.hpp"

CShield::CShield() : AComponent("Shield"), _healthOfShield(100), _isActivate(true) {}

void CShield::takeDamage(int power)
{
    if (_healthOfShield > 0 && _isActivate)
        _healthOfShield -= power;
}

void CShield::regeneration(int regen)
{
    if (_healthOfShield < 100 && _isActivate)
        _healthOfShield += regen;
}

void CShield::Disable() {
    if (_isActivate)
        _isActivate = false;
}

void        CShield::update() // JE C PAS QUOI METTRE DEDANS
{
    std::cout << "Shield : " << _healthOfShield << std::endl;
}