//
// Created by Oraekia on 16/01/18.
//

#ifndef CPP_RTYPE_AOBSTACLE_HPP
#define CPP_RTYPE_AOBSTACLE_HPP

#include <server/Components/CPosition.hpp>
#include <server/Components/CExplosion.hpp>
#include <server/Components/CHealth.hpp>
#include <server/Components/CScore.hpp>
#include <server/Components/CVelocity.hpp>
#include "AEntity.hpp"

namespace FF
{
    class AObstacle : public AEntity
    {
    public:
        AObstacle(EEntityType type) : AEntity(type)
        {
            this->addComponent(std::shared_ptr<AComponent>(new CPosition()));
            this->addComponent(std::shared_ptr<AComponent>(new CVelocity()));
            this->addComponent(std::shared_ptr<AComponent>(new CExplosion()));
            this->addComponent(std::shared_ptr<AComponent>(new CHealth()));
            this->addComponent(std::shared_ptr<AComponent>(new CScore()));
        }

        virtual FF::CPosition    move() = 0;
        virtual void    takeDamage(int power) = 0;
        virtual int     explosion() = 0;
        virtual void    setPosition(float x, float y) = 0;
        virtual int     score() = 0;

        virtual void init() = 0;
    };
}


#endif //CPP_RTYPE_AOBSTACLE_HPP
