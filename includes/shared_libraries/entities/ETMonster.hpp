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
        void takeDamage(int) final;
        void takeHealth(int) final;
        int scoreOfDie() final;
        int explosion() final;

        void init() final;
    };
}

#endif //CPP_RTYPE_ETMONSTER_HPP