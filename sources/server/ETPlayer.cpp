//
// Created by Oraekia on 09/01/18.
//

#include "server/ETPlayer.hpp"

ETPlayer::ETPlayer() : AEntity("Player")
{
    this->addComponent(new CPosition());
    this->addComponent(new CVelocity());
}
