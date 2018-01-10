//
// Created by pashervz on 10/01/18.
//

#include <server/AComponent.hpp>
#include "server/Components/CDisplay.hpp"

CDisplay::CDisplay(EDisplayType type) : AComponent("Display"), _type(type) {}

void                CDisplay::update() {}

