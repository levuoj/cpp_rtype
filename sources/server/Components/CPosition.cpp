//
// Created by pashervz on 09/01/18.
//

#include <iostream>
#include "server/CPosition.hpp"

CPosition::CPosition() : AComponent("Position"), _posX(0), _posY(0) {}

void        CPosition::update()
{
    std::cout << "La position X est : " << _posX << std::endl;
    std::cout << "La position Y est : " << _posY << std::endl;
}