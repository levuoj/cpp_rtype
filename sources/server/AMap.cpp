//
// Created by pashervz on 15/01/18.
//

#include <iostream>
#include "server/AMap.hpp"

bool                FF::AMap::isValid(FF::CPosition const &pos) const
{
    if ((pos.getX() < _length && pos.getX() > 0) && (pos.getY() < _width && pos.getY() > 0))
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
        std::cout << "[" << it.first->getX() << ", " << it.first->getY() << "] ";
        std::cout << ": " << it.second.id << ", " << it.second.element << std::endl;
    }
}

bool                FF::AMap::putElem(FF::CPosition const &pos, MapElem const &elem)
{
    if (!isValid(pos))
        return false;
    _map.insert(std::make_pair(std::make_unique<FF::CPosition>(pos), elem));
    return true;
}