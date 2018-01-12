//
// Created by pashervz on 12/01/18.
//

#ifndef CPP_RTYPE_APLAYER_HPP
#define CPP_RTYPE_APLAYER_HPP

#include "ABasicEntity.hpp"

class           APlayer : public ABasicEntity
{
public:
    APlayer() : ABasicEntity("Player") {}
    ~APlayer() = default;

    virtual void    shoot() = 0;
    virtual void    init() = 0;
};

#endif //CPP_RTYPE_APLAYER_HPP
