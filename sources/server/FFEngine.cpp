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
    _sessions.push_back(GameSession(std::bind(&FF::FFEngine::sending, this, std::placeholders::_1)));
    for (auto & it : _sessions)
    {
        it.initSession();
    }
}
