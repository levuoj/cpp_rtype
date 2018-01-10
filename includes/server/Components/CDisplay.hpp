//
// Created by pashervz on 10/01/18.
//

#ifndef CPP_RTYPE_CSPRITE_HPP
#define CPP_RTYPE_CSPRITE_HPP

#include <utils/EDisplayType.hpp>

class CDisplay : public AComponent {
private:
    EDisplayType         _type;
public:
    CDisplay(EDisplayType);

    virtual ~CDisplay() = default;

    virtual void    init();
    EDisplayType    getDisplayType() const { return _type; }
};


#endif //CPP_RTYPE_CSPRITE_HPP
