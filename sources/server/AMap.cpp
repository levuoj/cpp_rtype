//
// Created by pashervz on 15/01/18.
//

#include <iostream>
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

void                FF::AMap::displayMap() const
{
    for (const auto &it : _map)
    {
        std::cout << "[" << it.first.get()->getX() << ", " << it.first.get()->getY() << "] ";
        std::cout << ": " << it.second << std::endl;
    }
}

bool                FF::AMap::putElem(FF::CPosition const &pos, EElement elem)
{
    if (!isValid(pos))
        return false;
    _map.insert(std::make_pair(std::make_unique<FF::CPosition>(pos), elem));
    return true;
}