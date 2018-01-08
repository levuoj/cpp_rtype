//
// Created by pashervz on 08/01/18.
//

#ifndef CPP_RTYPE_IOBSTACLE_HPP
#define CPP_RTYPE_IOBSTACLE_HPP

#include "EDeathType.hpp"

class       IObstacle
{
public:
    void        takeDamage(int damage);
    EDeathType  death();
};

#endif //CPP_RTYPE_IOBSTACLE_HPP
