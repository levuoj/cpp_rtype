//
// Created by Oraekia on 13/01/18.
//

#ifndef CPP_RTYPE_AMONSTER_HPP
#define CPP_RTYPE_AMONSTER_HPP

#include <utils/EMoveType.hpp>
#include "AEntity.hpp"

namespace FF
{
    class AMonster : public AEntity
    {
    public:
        AMonster() : AEntity("Monster") {}
        ~AMonster() = default;

        virtual void move() = 0;
        virtual void takeDamage(int) = 0;
        virtual void takeHealth() = 0;
        virtual int scoreOfDie() = 0;
        virtual int explosion() = 0;

        virtual void init() = 0;
    };
}
#endif //CPP_RTYPE_AMONSTER_HPP
