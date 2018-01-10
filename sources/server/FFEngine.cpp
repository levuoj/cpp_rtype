//
// Created by pashervz on 10/01/18.
//

#include "server/FFEngine.hpp"

FF::FFEngine::FFEngine(Mediator & med) : AEngine(med) {}

void            FF::FFEngine::receive(Event const &)
{
    std::cout << "receive" << std::endl;
}

void            FF::FFEngine::launch()
{
    std::cout << "what to do, what to do..." << std::endl;
}