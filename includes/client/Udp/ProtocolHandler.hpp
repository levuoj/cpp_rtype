//
// Created by daze on 09/01/18.
//

#ifndef CPP_RTYPE_PROTOCOLHANDLER_HPP
#define CPP_RTYPE_PROTOCOLHANDLER_HPP

#include <QByteArray>
#include <QDebug>
#include <cstring>
#include "client/Event.hpp"

class ProtocolHandler
{
public:
    static Event ByteArrayToEv(QByteArray &buffer)
    {
        Event ev;
        ev.subType = SubType::FROMSERVER;

        QByteArray type;
        type.append(buffer[0]);
        type.append(buffer[1]);

        EventType a;
        std::memcpy(&a, type, sizeof(unsigned short));
        ev.type = a;

        QByteArray data;
        data = buffer.remove(0, 2);

        ev.datas = ProtocolHandler::QByteArrayToStringVec(buffer.size(), data);
        std::cout << "je suis ici" << std::endl;
        return (ev);
    }

    static std::vector<std::string> QByteArrayToStringVec(int size, QByteArray array) {
        std::vector<std::string> vec;
        int idx = 0;

        while (idx < size) {
            std::string buff;
            while (idx < size && array[idx] != '\0') {
                buff.append(1, array[idx]);
                idx++;
            }
            std::cout << "buff vec = " << buff << std::endl;
            vec.push_back(buff);
            idx++;
        }
        return (vec);
    }


    static QByteArray EventToByteArray(Event const &ev)
    {
        QByteArray buffer;
        char c = '\0';
        buffer = QByteArray(reinterpret_cast<const char *>(&ev.type), sizeof(ev.type));

        for (const auto &it : ev.datas)
        {
            buffer.append(it.c_str());
            buffer.append(c);
        }
        return (buffer);
    }
};

#endif //CPP_RTYPE_PROTOCOLHANDLER_HPP
