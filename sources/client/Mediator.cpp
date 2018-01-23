//
// Created by pashervz on 04/01/2018.
//
#include <thread>
#include "client/Graphic/GraphicManager.hpp"
#include "client/Udp/UdpManager.hpp"

    Mediator::Mediator() {
        // HOW TO ADD A MANAGER
        //    _managers.push_back(std::shared_ptr<AManager>(new AIBrain(*this)));
            //_managers.push_back(std::shared_ptr<AManager>(new Client::GraphicManager(*this)));
            _managers.push_back(std::shared_ptr<AManager>(new Client::UdpManager(*this)));
    }

    void Mediator::launch() {
        static_cast<Client::GraphicManager *>(_managers.at(1).get())->launch();
        // while (!static_cast<ProtocolManager *>(_managers.at(1).get())->getTerminate())  {
        //     static_cast<ProtocolManager *>(_managers.at(1).get())->readInfos();
        // }
    }

void Mediator::addManager(AManager *aManager)
{
    _managers.push_back(std::shared_ptr<AManager>(aManager));
}