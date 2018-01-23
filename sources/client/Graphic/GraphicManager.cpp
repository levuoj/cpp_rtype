//
// Created by myriam on 10/01/18.
//

#include <thread>
#include "client/Graphic/GraphicManager.hpp"

namespace   Client
{
    Client::GraphicManager::GraphicManager(Mediator &mediator) : AManager(mediator)
    {
        auto function = std::bind(&GraphicManager::notify, this, std::placeholders::_1);
        window = new SfmlWindow(function);

    }

    Client::GraphicManager::~GraphicManager()
    {

    }

    void    Client::GraphicManager::receive(Event const &)
    {
        //window.update(event)
    }

    void   Client::GraphicManager::notify(Event const &event)
    {
        sending(event);
    }

    void GraphicManager::launch()
    {
        window->startGame();
    }
}