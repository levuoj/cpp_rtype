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
    EShootType      shoot();
    void            move(EDirection dir);
    void            setSpeed(int speed);
    EDeathType      die();
    void            takeDamage(int damage);
};

#endif //CPP_RTYPE_IMONSTER_HPP
