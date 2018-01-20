//
// Created by myriam on 10/01/18.
//

#include "client/Graphic/GraphicManager.hpp"

namespace   Client
{
    Client::GraphicManager::GraphicManager(Mediator &mediator) : AManager(mediator)
    {

    }

    Client::GraphicManager::~GraphicManager()
    {

    }

    void    Client::GraphicManager::receive(Event const &)
    {
        //window.update(event)
    }
}