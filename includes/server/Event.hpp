//
// Created by pashervz on 04/01/2018.
//

#ifndef SERVER_EVENT_HPP
#define SERVER_EVENT_HPP

#include <iostream>
#include <vector>

enum EventType {
};

struct Event {
    EventType                    type;
    std::vector<std::string>     datas;
};

#endif //SERVER_EVENT_HPP
