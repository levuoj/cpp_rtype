//
// Created by Oraekia on 13/01/18.
//

#ifndef CPP_RTYPE_CARTIFICIALINTELLIGENCE_HPP
#define CPP_RTYPE_CARTIFICIALINTELLIGENCE_HPP


#include <server/AComponent.hpp>

class CArtificialIntelligence : public AComponent
{
public:
    CArtificialIntelligence();
    ~CArtificialIntelligence() = default;

    void    init() final;
};


#endif //CPP_RTYPE_CARTIFICIALINTELLIGENCE_HPP
