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
    EShootType      shoot();
    void            move();
    void            takeDamage();
    void            setPowerup(EPowerUpType powerUpType);
    void            die();
};

#endif //CPP_RTYPE_ICHARACTER_HPP
