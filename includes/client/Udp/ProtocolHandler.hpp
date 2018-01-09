//
// Created by daze on 09/01/18.
//

#ifndef CPP_RTYPE_PROTOCOLHANDLER_HPP
#define CPP_RTYPE_PROTOCOLHANDLER_HPP

#include <QByteArray>
#include <cstring>
#include "client/Event.hpp"

class ProtocolHandler
{
public:
    static Event ByteArrayToEv(QByteArray &buffer)
    {
        Event ev;
        ev.subType = SubType::FROMSERVER;

        QByteArray size;
        size.append(buffer[0]);
        size.append(buffer[1]);

        EventType a;
        std::memcpy(&a, size, sizeof(unsigned short));
        ev.type = a;

        QByteArray data;
        data = buffer.remove(0, 2);

        ev.datas = ProtocolHandler::QByteArrayToStringVec(buffer.size() - 2, data);
        return (ev);

    }

    static std::vector<std::string> QByteArrayToStringVec(int size, QByteArray array) {
        std::vector<std::string> vec;
        int idx = 0;

        while (idx < size) {
            std::string buff;
            while (idx < size && array[idx] != 0) {
                buff.append(1, array[idx]);
                idx++;
            }
            vec.push_back(buff);
            idx++;
        }
        return (vec);
    }


    static QByteArray EventToByteArray(Event const &ev)
    {
    }
};

#endif //CPP_RTYPE_PROTOCOLHANDLER_HPP
