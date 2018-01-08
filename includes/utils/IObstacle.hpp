//
// Created by pashervz on 08/01/18.
//

#ifndef CPP_RTYPE_IOBSTACLE_HPP
#define CPP_RTYPE_IOBSTACLE_HPP

#include "EDeathType.hpp"

class       IObstacle
{
public:
    virtual void        takeDamage(int damage) = 0;
    virtual EDeathType  death() = 0;
};

#endif //CPP_RTYPE_IOBSTACLE_HPP
