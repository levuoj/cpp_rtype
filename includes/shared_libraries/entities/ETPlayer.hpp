//
// Created by Oraekia on 09/01/18.
//

#pragma once

#include <server/ABasicEntity.hpp>
#include <server/APlayer.hpp>

class ETPlayer : public APlayer
{
public:
    ETPlayer();
    virtual ~ETPlayer() = default;

    void        init() final;
    void        move(EMoveType) final;
    void        shoot() final;
    void        takeDamage() final;
    void        killSomeone() final;
};