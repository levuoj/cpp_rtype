//
// Created by pashervz on 04/01/2018.
//

#include "client/AManager.hpp"

void AManager::sending(Event const & event) {
    std::cout << event.type << " " << event.datas.at(1) << std::endl;
    _mediator.transmit(event);
}
