//
// Created by daze on 09/01/18.
//

#ifndef CPP_RTYPE_PROTOCOLHANDLER_HPP
#define CPP_RTYPE_PROTOCOLHANDLER_HPP

//#include <QByteArray>
//#include <QDebug>
#include <cstring>
#include "utils/Event.hpp"

    class ProtocolHandler {
    public:
        static Event ByteArrayToEv(char *buffer) {
            Event ev;
            ev.subType = SubType::FROMSERVER;

            char type[3];
            type[0] = buffer[0];
            type[1] = buffer[1];
            type[2] = buffer[2];

            //EventType a = EventType::INPUT;
            //std::memcpy(&a, type, sizeof(unsigned short));
            unsigned short number = (unsigned short) strtoul(type, NULL, 0);
            ev.type = static_cast<EventType>(number);
            std::cout << "CODE ACTION = " << number << std::endl;

            std::string data;
            data = std::string(buffer).erase(0, 4);
            std::cout << "buffer pos 4 =" << buffer[3] << buffer[4] << buffer[5] << buffer[6] << buffer[7] << std::endl;
            std::cout << "data = " << data << std::endl;
            ev.datas = ProtocolHandler::ByteArrayToStringVec(std::string(buffer).length(), data.c_str());
            std::cout << "je suis ici" << std::endl;
            return (ev);
        }

        static std::vector<std::string> ByteArrayToStringVec(int size, const char *array) {
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

        static const char *EventToByteArray(Event const &ev) {
            std::string buffer;
            char c = '\0';
            buffer.append(std::to_string(ev.type));

            for (const auto &it : ev.datas) {
                buffer.append(it.c_str());
                buffer + c;
            }
            return (buffer.c_str());
        }
    };

#endif //CPP_RTYPE_PROTOCOLHANDLER_HPP
