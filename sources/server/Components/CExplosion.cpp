//
// Created by pashervz on 10/01/18.
//

#include "server/Components/CExplosion.hpp"

CExplosion::CExplosion() : AComponent("Explosion") {}

void            CExplosion::init() { _power = 0; }
