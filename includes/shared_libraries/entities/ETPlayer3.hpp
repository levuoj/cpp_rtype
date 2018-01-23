//
// Created by Oraekia on 09/01/18.
//

#pragma once

#include <server/APlayer.hpp>

namespace FF
{
    class ETPlayer3 : public APlayer
    {
        EMoveType _direction;
    public:
        ETPlayer3();
        virtual ~ETPlayer3() = default;

        void init() final;

        FF::CPosition move() final;
        void takeDamage() final;
        void killSomeone(EEntityType) final;
        void takeHealth() final;
        void takeShield() final;
        void setDirection(EMoveType dir) final { _direction = dir; }
    };
}