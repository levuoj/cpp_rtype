//
// Created by Oraekia on 16/01/18.
//

#pragma once

#include <server/AMissile.hpp>

namespace FF
{
    class ETBasicMissile : AMissile
    {
        EEntityType _typeOfLauncher;
    public:
        ETBasicMissile();
        virtual ~ETBasicMissile() = default;

        void    move() final;
        int    explosion() final;
        void    setLauncher(EEntityType type) {_typeOfLauncher = type; };

        virtual void init();
    };
}
