//
// Created by pashervz on 04/01/2018.
//

#include "utils/Mediator.hpp"
#include "server/FFEngine.hpp"
#include "server/UdpServer.hpp"

Mediator::Mediator()
{
    _managers.push_back(std::shared_ptr<AManager>(new FF::FFEngine(*this)));
    _managers.push_back(std::shared_ptr<AManager>(new Server::UdpServer(*this)));
}

void Mediator::launch() {
    static_cast<FF::FFEngine *>(_managers.at(0).get())->launch();
    static_cast<Server::UdpServer *>(_managers.at(0).get())->launch();
}
