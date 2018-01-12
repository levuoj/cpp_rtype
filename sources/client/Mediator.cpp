//
// Created by pashervz on 04/01/2018.
//

#include <utils/Mediator.hpp>
#include "utils/Mediator.hpp"

Mediator::Mediator()
{
  // HOW TO ADD A MANAGER
  //    _managers.push_back(std::shared_ptr<AManager>(new AIBrain(*this)));
}

void Mediator::launch() {
    // while (!static_cast<ProtocolManager *>(_managers.at(1).get())->getTerminate())  {
    //     static_cast<ProtocolManager *>(_managers.at(1).get())->readInfos();
    // }
}
