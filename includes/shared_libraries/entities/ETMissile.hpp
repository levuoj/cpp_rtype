//
// Created by Oraekia on 16/01/18.
//

#ifndef CPP_RTYPE_ETMISSILE_HPP
#define CPP_RTYPE_ETMISSILE_HPP


#include <server/AMissile.hpp>

namespace FF
{
    class ETMissile : AMissile
    {
        EEntityType _typeOfLauncher;
    public:
        ETMissile();
        virtual ~ETMissile() = default;

        void    move() final;
        int    explosion() final;
        void    setLauncher(EEntityType type) {_typeOfLauncher = type; };

        virtual void init();
    };
}

#endif //CPP_RTYPE_ETMISSILE_HPP
