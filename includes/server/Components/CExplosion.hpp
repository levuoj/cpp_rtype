//
// Created by pashervz on 10/01/18.
//

#ifndef CPP_RTYPE_CEXPLOSION_HPP
#define CPP_RTYPE_CEXPLOSION_HPP

#include <server/AComponent.hpp>

class CExplosion : public AComponent {
private:
    int         _power;

public:
    CExplosion();
    virtual ~CExplosion() = default;

    virtual void        init();

    int                 getPower() const { return _power; }
    void                setPower(int power) { _power = power; }
};


#endif //CPP_RTYPE_CEXPLOSION_HPP
