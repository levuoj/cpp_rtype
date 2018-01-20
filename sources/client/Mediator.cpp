//
// Created by pashervz on 04/01/2018.
//
#include <thread>
#include "client/Graphic/GraphicManager.hpp"
#include "client/Udp/UdpManager.hpp"

    Mediator::Mediator() {
        // HOW TO ADD A MANAGER
        //    _managers.push_back(std::shared_ptr<AManager>(new AIBrain(*this)));
        _managers.push_back(std::shared_ptr < AManager > (new Client::UdpManager(*this)));

        std::thread t([this]()
                      {
                          _managers.push_back(std::shared_ptr<AManager>(new Client::GraphicManager(*this)));
                      });
        t.join();
    }

    void Mediator::launch() {
        // while (!static_cast<ProtocolManager *>(_managers.at(1).get())->getTerminate())  {
        //     static_cast<ProtocolManager *>(_managers.at(1).get())->readInfos();
        // }
    }