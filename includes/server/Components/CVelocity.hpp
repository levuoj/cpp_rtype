//
// Created by pashervz on 09/01/18.
//

#ifndef CPP_RTYPE_CVELOCITY_HPP
#define CPP_RTYPE_CVELOCITY_HPP

#include "server/AComponent.hpp"

class CVelocity : public AComponent
{
private:
    float         _speed;

public:
    CVelocity();
    virtual ~CVelocity() = default;

    void                setSpeed(float speed) { _speed = speed; }
    float               getSpeed() const { return _speed; }
    void                update() override final;
};


#endif //CPP_RTYPE_CVELOCITY_HPP
