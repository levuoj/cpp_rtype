//
// Created by pashervz on 10/01/18.
//

#include "server/Components/CSound.hpp"
#include <server/AComponent.hpp>

CSound::CSound(ESoundType type) : AComponent("Sound"), _type(type) {}

void                CSound::init() {}