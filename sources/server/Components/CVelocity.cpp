//
// Created by pashervz on 09/01/18.
//

#include <iostream>
#include "server/Components/CVelocity.hpp"

CVelocity::CVelocity() : AComponent("Velocity"), _speed(0) {}

void            CVelocity::init()
{
    _speed = 0;
}