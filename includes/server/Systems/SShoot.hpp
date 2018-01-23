//
// Created by Oraekia on 17/01/18.
//

#ifndef CPP_RTYPE_SSHOOT_HPP
#define CPP_RTYPE_SSHOOT_HPP

#include <server/ASystem.hpp>

namespace FF
{
    class SShoot : public ASystem
    {
        std::function<void(EEntityType)>   _function;
        EEntityType                         _type;
    public:
        SShoot(std::function<void(EEntityType)> const & function, EEntityType type) : ASystem("Shoot"), _function(function), _type(type) {}
        virtual ~SShoot() = default;

        void        execute() final;
    };
}

#endif //CPP_RTYPE__SSHOOT_HPP