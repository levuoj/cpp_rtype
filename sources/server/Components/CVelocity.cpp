//
// Created by pashervz on 09/01/18.
//

#include <iostream>
#include "server/Components/CVelocity.hpp"

FF::CVelocity::CVelocity() : AComponent("CVelocity"), _speed(0) {}

void            FF::CVelocity::init()
{
    _speed = 0.5;
}