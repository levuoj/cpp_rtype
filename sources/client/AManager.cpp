//
// Created by pashervz on 04/01/2018.
//

#include <utils/Event.hpp>
#include <utils/AManager.hpp>

    void AManager::sending(Event const &event) {
        std::cout << "j'ai send l'event" << std::endl;
        _mediator.transmit(event);
    }
