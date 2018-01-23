//
// Created by daze on 09/01/18.
//

#ifndef CPP_RTYPE_PROTOCOLHANDLER_HPP
#define CPP_RTYPE_PROTOCOLHANDLER_HPP

#include <QByteArray>
#include <QDebug>
#include <cstring>
#include "utils/Event.hpp"

namespace Client {
    class ProtocolHandler {
    public:
        static Event ByteArrayToEv(QByteArray &buffer) {
            Event ev;
            ev.subType = SubType::FROMSERVER;

            QByteArray type;
            type.append(buffer[0]);
            type.append(buffer[1]);
            type.append(buffer[2]);


            unsigned short number = (unsigned short) strtoul(type, NULL, 0);
            ev.type = static_cast<EventType>(number);
//            std::cout << "CODE ACTION = " << number << std::endl;

            QByteArray data;
            data = buffer.remove(0, 4);
            ev.datas = ProtocolHandler::QByteArrayToStringVec(data.size(), data);
            std::cout << "je suis ici" << std::endl;
            return (ev);
        }

        static std::vector<std::string> QByteArrayToStringVec(int size, QByteArray array) {
            std::vector<std::string> vec;
            int idx = 0;

            while (idx < size) {
                std::string buff;
                while (idx < size && array[idx] != '\n') {
                    buff.append(1, array[idx]);
                    idx++;
                }
  //              std::cout << "buff vec = " << buff << std::endl;
                vec.push_back(buff);
                idx++;
            }
            return (vec);
        }


        static QByteArray EventToByteArray(Event const &ev) {
            QByteArray buffer;
            char c = '\n';
            buffer = QByteArray(std::to_string(ev.type).c_str());
            //buffer = QByteArray(reinterpret_cast<const char *>(&ev.type), sizeof(ev.type));
            buffer.append(c);
            for (const auto &it : ev.datas) {
                buffer.append(it.c_str());
                buffer.append(c);
            }
            return (buffer);
        }
    };
}
#endif //CPP_RTYPE_PROTOCOLHANDLER_HPP
