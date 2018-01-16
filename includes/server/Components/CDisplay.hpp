//
// Created by pashervz on 10/01/18.
//

#ifndef CPP_RTYPE_CSPRITE_HPP
#define CPP_RTYPE_CSPRITE_HPP

#include <utils/EDisplayType.hpp>

namespace FF
{
    class CDisplay : public AComponent
    {
    private:
        EDisplayType _type;
    public:
        CDisplay(EDisplayType);
        virtual ~CDisplay() = default;

        EDisplayType getDisplayType() const { return _type; }

        virtual void init();
    };
}

#endif //CPP_RTYPE_CSPRITE_HPP
