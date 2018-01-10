//
// Created by pashervz on 09/01/18.
//

#ifndef CPP_RTYPE_SMOVEMENT_HPP
#define CPP_RTYPE_SMOVEMENT_HPP

#include "server/ASystem.hpp"

class SMovement : public ASystem
{
public:
    SMovement();
    virtual ~SMovement() = default;

    void    execute() override final;
};


#endif //CPP_RTYPE_SMOVEMENT_HPP
