//
// Created by pashervz on 12/01/18.
//

#ifndef CPP_RTYPE_APLAYER_HPP
#define CPP_RTYPE_APLAYER_HPP

#include "AEntity.hpp"

class           APlayer : public AEntity
{
public:
    APlayer() : AEntity("Player") {}
    ~APlayer() = default;

    virtual void    init() = 0;
    virtual void    move(EMoveType) = 0;
    virtual void    shoot() = 0;
    virtual void    takeDamage() = 0;
    virtual void    killSomeone() = 0;
};

#endif //CPP_RTYPE_APLAYER_HPP
