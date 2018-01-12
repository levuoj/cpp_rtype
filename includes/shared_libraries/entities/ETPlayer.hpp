//
// Created by Oraekia on 09/01/18.
//

#pragma once

#include <server/AEntity.hpp>
#include <server/IPlayer.hpp>

class ETPlayer : public AEntity, public IPlayer
{
public:
    ETPlayer();
    virtual ~ETPlayer() = default;

    void        shoot() final;
    void        init() final;
};