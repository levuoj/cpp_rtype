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
        if (itET.second.get()->getType() == EEntityType::PLAYER1
            || itET.second.get()->getType() == EEntityType::PLAYER2
            || itET.second.get()->getType() == EEntityType::PLAYER3
            || itET.second.get()->getType() == EEntityType::PLAYER4)
        {
            FF::CPosition pos = reinterpret_cast<FF::APlayer *>(itET.second.get())->move();
            if (this->getMap()->doShifting(itET.second.get()->getId(), EElement::PLAYER, pos))
                reinterpret_cast<FF::APlayer *>(itET.second.get())->getPosition()->setXY(pos.getX(), pos.getY());
        }
        else if (itET.second.get()->getType() == EEntityType::BASICMONSTER)
        {
            FF::CPosition pos = reinterpret_cast<FF::AMonster *>(itET.second.get())->move();
            if (this->getMap()->doShifting(itET.second.get()->getId(), EElement::BASICMONSTER, pos))
                reinterpret_cast<FF::AMonster *>(itET.second.get())->getPosition()->setXY(pos.getX(), pos.getY());
        }
    }
}