//
// Created by Oraekia on 10/01/18.
//

#include <iostream>
#include "server/Components/CScore.hpp"

CScore::CScore() : AComponent("Score"), _score(0) {}

void CScore::init()
{
    _score = 0;
}