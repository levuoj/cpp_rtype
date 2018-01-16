//
// Created by Oraekia on 13/01/18.
//

#include <iostream>
#include "server/Components/CArtificialIntelligence.hpp"

FF::CArtificialIntelligence::CArtificialIntelligence() : AComponent("CAI") {}

void        FF::CArtificialIntelligence::init() {}

void FF::CArtificialIntelligence::move()
{
    std::cout << "Les Akatsukis sont les meilleurs." << std::endl;
}
