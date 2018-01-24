//
// Created by Oraekia on 13/01/18.
//

#ifndef CPP_RTYPE_AMONSTER_HPP
#define CPP_RTYPE_AMONSTER_HPP

#include <server/Components/CPosition.hpp>
#include <server/Components/CVelocity.hpp>
#include <server/Components/CHealth.hpp>
#include <server/Components/CArtificialIntelligence.hpp>
#include <server/Components/CScore.hpp>
#include <server/Components/CShield.hpp>
#include <server/Components/CExplosion.hpp>
#include <utils/EMoveType.hpp>
#include "AEntity.hpp"

namespace FF
{
    class AMonster : public AEntity
    {
    public:
        AMonster(EEntityType type) : AEntity(type)
        {
            this->addComponent(std::shared_ptr<AComponent>(new CArtificialIntelligence()));
            this->addComponent(std::shared_ptr<AComponent>(new CPosition()));
            this->addComponent(std::shared_ptr<AComponent>(new CVelocity()));
            this->addComponent(std::shared_ptr<AComponent>(new CHealth()));
            this->addComponent(std::shared_ptr<AComponent>(new CScore()));
            this->addComponent(std::shared_ptr<AComponent>(new CExplosion()));
        }

        ~AMonster() = default;

        virtual CPosition move() = 0;
        virtual void takeDamage(int) = 0;
        virtual void takeHealth() = 0;
        virtual int scoreOfDie() = 0;
        virtual int explosion() = 0;
        virtual void init() = 0;

        CPosition       *getPosition() const
        {
            return (reinterpret_cast<CPosition *>(this->getComponent("CPosition")));
        }
    };
}
#endif //CPP_RTYPE_AMONSTER_HPP
