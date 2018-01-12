//
// Created by pashervz on 10/01/18.
//

#ifndef CPP_RTYPE_IENGINE_HPP
#define CPP_RTYPE_IENGINE_HPP

#include <utils/AManager.hpp>

class AEngine : public AManager
{
public:
    AEngine(Mediator & med) : AManager(med) {}
    virtual ~AEngine() = default;
    virtual void receive(Event const &) = 0;
    virtual void launch() = 0;
};

#endif //CPP_RTYPE_IENGINE_HPP
