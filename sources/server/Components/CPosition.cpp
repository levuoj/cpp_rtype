//
// Created by pashervz on 09/01/18.
//

#include <iostream>
#include "server/Components/CPosition.hpp"

FF::CPosition::CPosition() : AComponent("CPosition"), _posX(0), _posY(0) {}

void        FF::CPosition::init()
{
    _posX = 0;
    _posY = 0;
}