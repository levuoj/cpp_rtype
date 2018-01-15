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
        virtual ~ETMonster() = default;

        void move() final;
        virtual void takeDamage(int) final;
        virtual void takeHealth() final;
        virtual int scoreOfDie() final;
        virtual int explosion() final;

        void init() final;
    };
}

#endif //CPP_RTYPE_ETMONSTER_HPP