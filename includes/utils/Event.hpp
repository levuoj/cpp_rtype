//
// Created by pashervz on 04/01/2018.
//

#ifndef CLIENT_EVENT_HPP
#define CLIENT_EVENT_HPP

#include <iostream>
#include <vector>

    enum SubType {
        FROMCLIENT, // EVENTS CREATED IN THE CLIENT
        FROMSERVER  // EVENTS CREATED IN THE SERVER
    };

    enum EventType {

        // CLIENT TO SERVER

        NEWGAME = 100,
        JOINGAME = 110,
        QUITGAME = 120,
        INPUT = 130,

        // SERVER TO CLIENT

        UPDATE = 200,
        CONNECTEDLOBBY = 210,
        STARTGAME = 220,
        WIN = 230,
        LOOSE = 240,
        DIE = 250,
        UPDATESCORE = 260
    };

    struct Event {
        EventType type;
        SubType subType;
        std::vector<std::string> datas;
    };

#endif //CLIENT_EVENT_HPP
