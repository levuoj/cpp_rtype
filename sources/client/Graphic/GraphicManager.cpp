//
// Created by myriam on 10/01/18.
//

#include "client/Graphic/GraphicManager.hpp"

namespace   Client
{
    Client::GraphicManager::GraphicManager(Mediator &mediator) : AManager(mediator)
    {
        auto function = std::bind(&GraphicManager::notify, this, std::placeholders::_1);
        window = new SfmlWindow(function);
        window->startGame();
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
        std::cout << "EVENT SEND "  << event.type << std::endl;
        sending(event);
    }
}