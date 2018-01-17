//
// Created by pashervz on 04/01/2018.
//

#ifndef SERVER_EVENT_HPP
#define SERVER_EVENT_HPP

#include <iostream>
#include <vector>
struct Event {

    enum EventType
    {
        SENDING_MAP
    };

    EventType                    type;

    explicit Event(EventType t) : type(t) {}
};

#endif //SERVER_EVENT_HPP
