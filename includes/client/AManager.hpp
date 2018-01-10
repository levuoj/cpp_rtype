//
// Created by pashervz on 04/01/2018.
//

#ifndef CLIENT_AMANAGER_HPP
#define CLIENT_AMANAGER_HPP

#include "Event.hpp"

namespace  Client {
    class Mediator;

    class AManager {
    protected:
        Mediator &_mediator;

    public:
        AManager(Mediator &mediator) : _mediator(mediator) {}

        virtual ~AManager() = default;

        virtual void receive(Event const &) = 0;

        void sending(Event const &);
    };

}

#include "Mediator.hpp"

#endif //CLIENT_AMANAGER_HPP
