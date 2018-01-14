//
// Created by Oraekia on 13/01/18.
//

#ifndef CPP_RTYPE_AMONSTER_HPP
#define CPP_RTYPE_AMONSTER_HPP

#include "AEntity.hpp"

class               AMonster : public AEntity
{
public:
    AMonster() : AEntity("Monster") {}
    ~AMonster() = default;

    virtual void    init() = 0;
    virtual void    move() = 0;
    virtual void    takeDamage() = 0;
    virtual void    takeHealth() = 0;
    virtual void    takeShield() = 0;
};

#endif //CPP_RTYPE_AMONSTER_HPP
