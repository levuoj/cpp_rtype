//
// Created by Oraekia on 13/01/18.
//

#ifndef CPP_RTYPE_CARTIFICIALINTELLIGENCE_HPP
#define CPP_RTYPE_CARTIFICIALINTELLIGENCE_HPP


#include <server/AComponent.hpp>

namespace FF
{
    class CArtificialIntelligence : public AComponent
    {
    public:
        CArtificialIntelligence();
        virtual ~CArtificialIntelligence() = default;

        void    move();

        void init() final;
    };
}

#endif //CPP_RTYPE_CARTIFICIALINTELLIGENCE_HPP
