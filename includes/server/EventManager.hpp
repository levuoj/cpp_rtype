//
// Created by pashervz on 23/01/18.
//

#ifndef CPP_RTYPE_EVENTMANAGER_HPP
#define CPP_RTYPE_EVENTMANAGER_HPP


#include <utils/Event.hpp>
#include <queue>
#include "ActionManager.hpp"

namespace FF {
    class EventManager {
    private:
        std::queue<Event> _eventQueue;

    public:
        EventManager() = default;

        ~EventManager() = default;

        void push(Event event) { _eventQueue.push(event); }

        Action treat();
    };
}

#endif //CPP_RTYPE_EVENTMANAGER_HPP
