//
// Created by Oraekia on 17/01/18.
//

#ifndef CPP_RTYPE_SSHOOT_HPP
#define CPP_RTYPE_SSHOOT_HPP

#include <server/ASystem.hpp>
#include <utility>

namespace FF
{
    class SShoot : public ASystem
    {
        std::function<void(EEntityType)>   _callback;
    public:
        SShoot();
        ~SShoot() final = default;

        void    execute() final;
        void    setCallback(std::function<void(EEntityType)> func) { _callback = std::move(func); }
    };
}


#endif //CPP_RTYPE_SSHOOT_HPP
