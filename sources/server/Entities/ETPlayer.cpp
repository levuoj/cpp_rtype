//
// Created by Oraekia on 09/01/18.
//

#include "server/Entities/ETPlayer.hpp"
#include "server/Components/CPosition.hpp"
#include "server/Components/CVelocity.hpp"

ETPlayer::ETPlayer() : AEntity("Player")
{
    this->addComponent(std::shared_ptr<AComponent>(new CPosition()));
    this->addComponent(std::shared_ptr<AComponent>(new CVelocity()));
}
