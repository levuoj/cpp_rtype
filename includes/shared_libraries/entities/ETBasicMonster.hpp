//
// Created by Oraekia on 13/01/18.
//

#pragma once

#include <server/AMonster.hpp>

namespace FF
{
    class ETBasicMonster : public AMonster
    {
    public:
        ETBasicMonster();
        virtual ~ETBasicMonster() = default;

        void move() final;
        void takeDamage(int) final;
        void takeHealth() final;
        int scoreOfDie() final;
        int explosion() final;

        void init() final;
    };
}