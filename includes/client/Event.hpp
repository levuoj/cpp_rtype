//
// Created by pashervz on 04/01/2018.
//

#ifndef CLIENT_EVENT_HPP
#define CLIENT_EVENT_HPP

#include <iostream>
#include <vector>

enum EventType
{

};

struct Event {
    EventType                    type;
    std::vector<std::string>     datas;
};

#endif //CLIENT_EVENT_HPP
