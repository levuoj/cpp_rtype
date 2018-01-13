//
// Created by Oraekia on 10/01/18.
//

#ifndef CPP_RTYPE_CHEALTH_HPP
#define CPP_RTYPE_CHEALTH_HPP


#include <printf.h>
#include <server/AComponent.hpp>

class CHealth : public AComponent
{
private:
    int     _health;
public:
    CHealth();
    virtual ~CHealth() = default;

    void    reduceHealth(int reduce);
    void    reduceHealth();
    void    increaseHealth(int increase);
    void    increaseHealth();
    void    setHealth(int health) { _health = health; }
    int     getHealt() const { return (_health); }

    void    init() final;
};


#endif //CPP_RTYPE_CHEALTH_HPP
