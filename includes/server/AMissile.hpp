//
// Created by Oraekia on 16/01/18.
//

#ifndef CPP_RTYPE_AMISSILE_HPP
#define CPP_RTYPE_AMISSILE_HPP

#include <server/Components/CPosition.hpp>
#include <server/Components/CVelocity.hpp>
#include <server/Components/CExplosion.hpp>
#include "AEntity.hpp"

namespace FF
{
    class AMissile : public AEntity
    {
    public:
        AMissile(EEntityType type) : AEntity(type)
        {
            this->addComponent(std::shared_ptr<AComponent>(new CPosition()));
            this->addComponent(std::shared_ptr<AComponent>(new CVelocity()));
            this->addComponent(std::shared_ptr<AComponent>(new CExplosion()));
        }
        virtual ~AMissile() = default;

        virtual FF::CPosition move() = 0;
        virtual int explosion() = 0;
        CPosition       *getPosition() const
        {
            return (reinterpret_cast<CPosition *>(this->getComponent("CPosition")));
        }
    };
}

#endif //CPP_RTYPE_AMISSILE_HPP
