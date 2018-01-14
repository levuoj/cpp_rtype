//
// Created by Oraekia on 09/01/18.
//

#pragma once

#include <server/APlayer.hpp>

namespace FF
{
    class ETPlayer : public APlayer
    {
    public:
        ETPlayer();
        virtual ~ETPlayer() = default;

        void init() final;

        void move(EMoveType) final;
        void takeDamage() final;
        void killSomeone(EEntityType) final;
        void takeHealth() final;
        void takeShield() final;
    };
}