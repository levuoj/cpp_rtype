//
// Created by pashervz on 09/01/18.
//

#include <server/APlayer.hpp>
#include <server/AMonster.hpp>
#include "server/Systems/SMovement.hpp"

FF::SMovement::SMovement() : ASystem("Movement") {}

void            FF::SMovement::execute()
{
    for (const auto & itET : _entities)
    {
        if (itET.second.get()->getType() == EEntityType::PLAYER)
        {
            FF::CPosition pos = reinterpret_cast<FF::APlayer *>(itET.second.get())->move();
            if (this->getMap()->doShifting(itET.second.get()->getId(), EElement::PLAYER, pos))
                reinterpret_cast<FF::APlayer *>(itET.second.get())->getPositon()->setXY(pos.getX(), pos.getY());
        }
        else if (itET.second.get()->getType() == EEntityType::MONSTER)
        {
            FF::CPosition pos = reinterpret_cast<FF::AMonster *>(itET.second.get())->move();
            if (this->getMap()->doShifting(itET.second.get()->getId(), EElement::MONSTER, pos))
                reinterpret_cast<FF::AMonster *>(itET.second.get())->getPositon()->setXY(pos.getX(), pos.getY());
        }
    }
}