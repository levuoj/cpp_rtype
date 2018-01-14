//
// Created by Oraekia on 13/01/18.
//

#ifndef CPP_RTYPE_ETMONSTER_HPP
#define CPP_RTYPE_ETMONSTER_HPP


#include <server/AMonster.hpp>

class ETMonster : public AMonster
{
public:
    ETMonster();
    ~ETMonster() {}

    void    init() final;
    void    move() final;
    void    takeDamage() final;
    void    takeHealth() final;
    void    takeShield() final;
};


#endif //CPP_RTYPE_ETMONSTER_HPP
