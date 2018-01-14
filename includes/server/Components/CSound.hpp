//
// Created by pashervz on 10/01/18.
//

#ifndef CPP_RTYPE_CSOUND_HPP
#define CPP_RTYPE_CSOUND_HPP

#include <utils/ESoundType.hpp>
#include <server/AComponent.hpp>

namespace FF
{
    class CSound : public AComponent
    {
    private:
        ESoundType _type;
    public:
        CSound(ESoundType);
        virtual ~CSound() = default;

        ESoundType getSoundType() const { return _type; }

        virtual void init() final;
    };
}

#endif //CPP_RTYPE_CSOUND_HPP
