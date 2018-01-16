//
// Created by pashervz on 12/01/18.
//

#ifndef CPP_RTYPE_APLAYER_HPP
#define CPP_RTYPE_APLAYER_HPP

#include "utils/EMoveType.hpp"
#include "AEntity.hpp"
#include "EEntityType.hpp"

namespace FF {
    class APlayer : public AEntity {
    public:
        APlayer() : AEntity("Player") {}
        ~APlayer() = default;

        virtual void init() = 0;

        virtual void move() = 0;
        virtual void takeDamage() = 0;
        virtual void killSomeone(EEntityType) = 0;
        virtual void takeHealth() = 0;
        virtual void takeShield() = 0;
        virtual void setDirection(EMoveType) = 0;
    };
}
#endif //CPP_RTYPE_APLAYER_HPP
