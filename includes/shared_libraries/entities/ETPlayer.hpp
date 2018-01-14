//
// Created by Oraekia on 09/01/18.
//

#pragma once

#include <server/AEntity.hpp>
#include <server/APlayer.hpp>

class ETPlayer : public APlayer
{
public:
    ETPlayer();
    virtual ~ETPlayer() = default;

    void        shoot() final;
    void        init() final;
};