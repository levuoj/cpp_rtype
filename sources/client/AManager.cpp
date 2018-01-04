//
// Created by pashervz on 04/01/2018.
//

#include "client/AManager.hpp"

void AManager::sending(Event const & event) {
    _mediator.transmit(event);
}
