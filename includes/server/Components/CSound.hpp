//
// Created by pashervz on 10/01/18.
//

#ifndef CPP_RTYPE_CSOUND_HPP
#define CPP_RTYPE_CSOUND_HPP

#include <utils/ESoundType.hpp>
#include <server/AComponent.hpp>

class CSound : public AComponent {
private:
    ESoundType         _type;
public:
    CSound(ESoundType);

    virtual ~CSound() = default;

    virtual void    init() final;

    ESoundType    getSoundType() const { return _type; }
};

#endif //CPP_RTYPE_CSOUND_HPP
