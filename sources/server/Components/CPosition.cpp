//
// Created by pashervz on 09/01/18.
//

#include <iostream>
#include "server/Components/CPosition.hpp"

CPosition::CPosition() : AComponent("Position"), _posX(0), _posY(0) {}

void        CPosition::init()
{
    _posX = 0;
    _posY = 0;
}