//
// Created by pashervz on 08/01/18.
//

#ifndef CPP_RTYPE_IMONSTER_HPP
#define CPP_RTYPE_IMONSTER_HPP

#include "EShootType.hpp"
#include "EDirection.hpp"
#include "EDeathType.hpp"

class       IMonster
{
public:
    virtual EShootType      shoot() = 0;
    virtual void            move(EDirection dir) = 0;
    virtual void            setSpeed(int speed) = 0;
    virtual EDeathType      die() = 0;
    virtual void            takeDamage(int damage) = 0;
};

#endif //CPP_RTYPE_IMONSTER_HPP
