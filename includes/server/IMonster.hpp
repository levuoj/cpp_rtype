//
// Created by pashervz on 08/01/18.
//

#ifndef CPP_RTYPE_IMONSTER_HPP
#define CPP_RTYPE_IMONSTER_HPP

#include <utils/EShootType.hpp>
#include <utils/EDirection.hpp>
#include <utils/EDeathType.hpp>

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
