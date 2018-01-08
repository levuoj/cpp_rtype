//
// Created by pashervz on 08/01/18.
//

#ifndef CPP_RTYPE_ICHARACTER_HPP
#define CPP_RTYPE_ICHARACTER_HPP

#include "EShootType.hpp"
#include "EPowerUpType.hpp"

class               ICharacter
{
public:
    virtual EShootType      shoot() = 0;
    virtual void            move() = 0;
    virtual void            takeDamage() = 0;
    virtual void            setPowerup(EPowerUpType powerUpType) = 0;
    virtual void            die() = 0;
};

#endif //CPP_RTYPE_ICHARACTER_HPP
