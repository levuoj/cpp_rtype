//
// Created by Oraekia on 17/01/18.
//

#include <server/Systems/SShoot.hpp>
#include <server/APlayer.hpp>
#include <server/AMissile.hpp>

void FF::SShoot::execute()
{
    if (!_toggle)
        return;
    for (const auto &itET : _entities)
    {
        if (itET.second.get()->getType() == EEntityType::PLAYER1
                || itET.second.get()->getType() == EEntityType::PLAYER2
                || itET.second.get()->getType() == EEntityType::PLAYER3
                || itET.second.get()->getType() == EEntityType::PLAYER4)
        {
            CPosition pos = *reinterpret_cast<FF::APlayer *>(itET.second.get())->getPosition();
            pos.setX(pos.getX() + 1);
            if (this->getMap()->doShifting(itET.second.get()->getId(), EElement::PLAYER, pos))
                if (_type == EEntityType::PLAYERMISSILE)
                    _function(_type);
        }
    }
}
