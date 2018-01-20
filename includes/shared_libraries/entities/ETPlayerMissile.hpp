//
// Created by Oraekia on 16/01/18.
//

#pragma once

#include <server/AMissile.hpp>

namespace FF
{
    class ETBasicMissile : AMissile
    {
    public:
        ETBasicMissile();
        virtual ~ETBasicMissile() = default;

        FF::CPosition    move() final;
        int              explosion() final;
        virtual void     init();
    };
}