//
// Created by pashervz on 10/01/18.
//

#ifndef CPP_RTYPE_CMUSIC_HPP
#define CPP_RTYPE_CMUSIC_HPP

#include <server/AComponent.hpp>
#include <utils/EMusicType.hpp>

class CMusic : public AComponent {
private:
    EMusicType         _type;

public:
    CMusic(EMusicType);

    virtual ~CMusic() = default;

    virtual void    init() final;

    EMusicType    getMusicType() const { return _type; }
};



#endif //CPP_RTYPE_CMUSIC_HPP
