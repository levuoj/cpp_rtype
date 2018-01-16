//
// Created by pashervz on 10/01/18.
//

#ifndef CPP_RTYPE_CMUSIC_HPP
#define CPP_RTYPE_CMUSIC_HPP

#include <server/AComponent.hpp>
#include <utils/EMusicType.hpp>

namespace FF
{
    class CMusic : public AComponent
    {
    private:
        EMusicType _type;

    public:
        CMusic(EMusicType);
        virtual ~CMusic() = default;

        EMusicType getMusicType() const { return _type; }

        virtual void init() final;
    };
}



#endif //CPP_RTYPE_CMUSIC_HPP
