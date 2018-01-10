//
// Created by Oraekia on 10/01/18.
//

#include <iostream>
#include "server/Components/CScore.hpp"

CScore::CScore() : AComponent("Score"), _score(0) {}

void CScore::update() //QUE FAIRE ?
{
    std::cout << "Mon score est de : " << _score << std::endl;
}