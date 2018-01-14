//
// Created by Oraekia on 13/01/18.
//

#ifndef CPP_RTYPE_ETMONSTER_HPP
#define CPP_RTYPE_ETMONSTER_HPP

#include <server/AMonster.hpp>

namespace FF
{
    class ETMonster : public AMonster
    {
    public:
        ETMonster();
        virtual ~ETMonster() {}

        void init() final;
        void move() final;
        void takeDamage() final;
        void takeHealth() final;
        void takeShield() final;
    };
}

#endif //CPP_RTYPE_ETMONSTER_HPP