//
// Created by pashervz on 04/01/2018.
//

#include "utils/Mediator.hpp"
#include "server/FFEngine.hpp"
#include "server/Network/UdpServer.hpp"

Mediator::Mediator()
{
    _managers.push_back(std::shared_ptr<AManager>(new FF::FFEngine(*this)));
}

void Mediator::launch() {
    static_cast<FF::FFEngine *>(_managers.at(0).get())->launch();
}

void Mediator::addManager(AManager *aManager)
{
    _managers.push_back(std::shared_ptr<AManager>(aManager));
}