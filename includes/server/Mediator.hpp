//
// Created by pashervz on 04/01/2018.
//

#ifndef SERVER_MEDIATOR_HPP
#define SERVER_MEDIATOR_HPP

#include <memory>
#include <vector>
#include <memory>
#include "AManager.hpp"
#include "Event.hpp"

class Mediator {
private:
    std::vector<std::shared_ptr<AManager>>      _managers;
public:
    Mediator();
    ~Mediator() = default;

    void        transmit(Event const & event) {
        for (auto const & it : _managers) {
            it->receive(event);
        }
    }

    void        launch();
};


#endif //SERVER_MEDIATOR_HPP
