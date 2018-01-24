//
// Created by pashervz on 15/01/18.
//

#include <iostream>
#include "shared_libraries/entities/ETLevel1.hpp"

FF::ETLevel1::ETLevel1(float length, float width) : FF::AMap(length, width, EEntityType::MAP) {
    this->init();
}

void                FF::ETLevel1::init()
{
    this->setLimits();
}

void                FF::ETLevel1::setLimits()
{
    for (float i = 0; i < _length; i += 1.0f)
    {
        _map.insert(std::make_pair(std::unique_ptr<FF::CPosition>(new FF::CPosition(i, 0.0f)), MapElem(EElement::BORDER, -1)));
        _map.insert(std::make_pair(std::unique_ptr<FF::CPosition>(new FF::CPosition(i, 20.0f)), MapElem(EElement::BORDER, -1)));
    }
}

bool                FF::ETLevel1::doShifting(int id, EElement elem, FF::CPosition const & pos)
{
    if (!isValid(pos))
        return false;
    for (auto it = _map.begin(); it != _map.end(); ++it)
    {
        if (it->second.id == id)
            _map.erase(it);
    }
    this->putElem(pos, MapElem(elem, id));
    return true;
}

extern "C"
{
    FF::AMap        *create()
    {
        return (new FF::ETLevel1(60.0f, 20.0f));
    }
}