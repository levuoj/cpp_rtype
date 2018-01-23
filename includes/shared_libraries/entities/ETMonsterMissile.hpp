//
// Created by Oraekia on 16/01/18.
//

#pragma once

#include <server/AMissile.hpp>

namespace FF
{
    class ETMonsterMissile : public AMissile
    {
    public:
        ETMonsterMissile();
        virtual ~ETMonsterMissile() = default;

        FF::CPosition    move() final;
        int              explosion() final;

        void     init() final;
    };
}