//
// Created by pashervz on 15/01/18.
//

#include "server/AMap.hpp"

bool                FF::AMap::isValid(FF::CPosition const &pos) const
{
    if (pos.getX() < _length && pos.getY() < _width)
    {
        for (const auto & it : _map)
        {
            if (&pos == it.first.get())
                return false;
        }
        return true;
    }
    return false;
}