//
// Created by pashervz on 10/01/18.
//

#include "server/Components/CSound.hpp"
#include <server/AComponent.hpp>

FF::CSound::CSound(ESoundType type) : AComponent("CSound"), _type(type) {}

void                FF::CSound::init() {}