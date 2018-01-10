//
// Created by Oraekia on 10/01/18.
//

#include <iostream>
#include "server/Components/CMissile.hpp"

CMissile::CMissile() : AComponent("Missile"), _power(50) {}

void CMissile::update()
{
    std::cout << "la puissance de mon missile est de : " << _power << std::endl;
}
