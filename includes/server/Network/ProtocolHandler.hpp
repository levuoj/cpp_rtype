//
// Created by daze on 09/01/18.
//

#ifndef CPP_RTYPE_PROTOCOLHANDLER_HPP
#define CPP_RTYPE_PROTOCOLHANDLER_HPP

#include <cstring>
#include "utils/Event.hpp"

namespace Server {
    class ProtocolHandler {
    public:
        static Event ByteArrayToEv(char *buffer, size_t size) {
            std::cout.write(buffer, size);
            Event ev;
            ev.subType = SubType::FROMSERVER;

            char type[3];
            type[0] = buffer[0];
            type[1] = buffer[1];
            type[2] = buffer[2];

            unsigned short number = (unsigned short) strtoul(type, NULL, 0);
            ev.type = static_cast<EventType>(number);

            std::string data;
            data = std::string(buffer).erase(0, 4);
            ev.datas = ProtocolHandler::ByteArrayToStringVec(std::string(data).size(), data);
            return (ev);
        }

        static std::vector<std::string> ByteArrayToStringVec(int size, std::string array) {
          //  std::cout << "START " << __FUNCTION__ << std::endl;
            std::vector<std::string> vec;
            int idx = 0;
            while (idx < size) {
                std::string buff;
                while (idx < size && array[idx] != '\n') {
                    buff.append(1, array[idx]);
                    idx++;
                }
        //        std::cout << "buff vec = " << buff << std::endl;
                vec.push_back(buff);
                idx++;
            }
      //      std::cout << "END " << __FUNCTION__ << std::endl;
            return (vec);
        }

        static std::string EventToByteArray(Event const &ev) {
            std::cout << "START " << __FUNCTION__ << std::endl;

            std::string buffer;
            char c = '\n';
            buffer.append(std::to_string(ev.type));
            buffer += c;
            for (const auto &it : ev.datas) {
                buffer.append(it.c_str());
                buffer += c;
            }
            //std::cout.write(buffer.c_str(), 100);
            return (buffer);
        }
    };
}

#endif //CPP_RTYPE_PROTOCOLHANDLER_HPP
