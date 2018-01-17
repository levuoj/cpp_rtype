//
// Created by pashervz on 04/01/2018.
//

#include "utils/AManager.hpp"

void        AManager::sending(Event const & event) {
    _mediator.transmit(event);
    std::cout << "bite" << std::endl;
    for (auto const& it : event.datas)
        std::cout << it << std::endl;
}
