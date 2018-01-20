//
// Created by pashervz on 20/01/18.
//

#ifndef CPP_RTYPE_SSPAWN_HPP
#define CPP_RTYPE_SSPAWN_HPP

#include <server/ASystem.hpp>

namespace FF {
    class SSpawn : public ASystem
    {
    private:
        std::function<void(EEntityType)>        _function;
        EEntityType                             _type;

    public:
        SSpawn(std::function<void(EEntityType)> const &, EEntityType);
        ~SSpawn() override = default;

        void execute() final;
    };
}
#endif //CPP_RTYPE_SSPAWN_HPP
