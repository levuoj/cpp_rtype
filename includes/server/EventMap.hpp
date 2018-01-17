//
// Created by pashervz on 17/01/18.
//

#ifndef CPP_RTYPE_EVENTMAP_HPP
#define CPP_RTYPE_EVENTMAP_HPP

#include <utils/Event.hpp>
#include "MapPacket.hpp"

struct EventMap : public Event
{
    MapPacket       mapPacket;
    EventMap() : Event(SENDING_MAP) {}
};

#endif //CPP_RTYPE_EVENTMAP_HPP
