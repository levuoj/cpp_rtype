//
// Created by pashervz on 10/01/18.
//

#include "server/Components/CExplosion.hpp"

FF::CExplosion::CExplosion() : AComponent("Explosion") {}

void            FF::CExplosion::init() { _power = 0; }
