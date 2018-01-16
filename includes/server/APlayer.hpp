//
// Created by pashervz on 12/01/18.
//

#ifndef CPP_RTYPE_APLAYER_HPP
#define CPP_RTYPE_APLAYER_HPP

#include <server/Components/CPosition.hpp>
#include <server/Components/CVelocity.hpp>
#include <server/Components/CScore.hpp>
#include <server/Components/CHealth.hpp>
#include <server/Components/CShield.hpp>
#include "utils/EMoveType.hpp"
#include "AEntity.hpp"
#include "EEntityType.hpp"

namespace FF {
    class APlayer : public AEntity {
    public:
        APlayer(EEntityType type) : AEntity(type)
        {
            this->addComponent(std::shared_ptr<AComponent>(new CPosition()));
            this->addComponent(std::shared_ptr<AComponent>(new CVelocity()));
            this->addComponent(std::shared_ptr<AComponent>(new CHealth()));
            this->addComponent(std::shared_ptr<AComponent>(new CScore()));
            this->addComponent(std::shared_ptr<AComponent>(new CShield()));
        }

        ~APlayer() = default;

        virtual void init() = 0;

        virtual CPosition move() = 0;
        virtual void takeDamage() = 0;
        virtual void killSomeone(EEntityType) = 0;
        virtual void takeHealth() = 0;
        virtual void takeShield() = 0;
        virtual void setDirection(EMoveType) = 0;
        CPosition       *getPositon() const
        {
            return (reinterpret_cast<CPosition *>(this->getComponent("CPosition")));
        }
    };
}
#endif //CPP_RTYPE_APLAYER_HPP
