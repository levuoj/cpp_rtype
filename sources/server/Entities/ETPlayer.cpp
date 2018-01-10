//
// Created by Oraekia on 09/01/18.
//

#include "server/ETPlayer.hpp"
#include "server/CPosition.hpp"
#include "server/CVelocity.hpp"

ETPlayer::ETPlayer() : AEntity("Player")
{
    this->addComponent(std::shared_ptr<AComponent>(new CPosition()));
    this->addComponent(std::shared_ptr<AComponent>(new CVelocity()));
}
