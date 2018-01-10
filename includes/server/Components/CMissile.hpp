//
// Created by Oraekia on 10/01/18.
//

#ifndef CPP_RTYPE_CMISSILE_HPP
#define CPP_RTYPE_CMISSILE_HPP


#include <server/AComponent.hpp>

class CMissile : public AComponent
{
private:
    int     _power;
public:
    CMissile();
    virtual ~CMissile() = default;

    void    setPower(int power) { _power = power; }
    int     getPower() const { return (_power); }

    void    update() final;
};


#endif //CPP_RTYPE_CMISSILE_HPP
