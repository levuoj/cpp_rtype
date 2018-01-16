//
// Created by pashervz on 15/01/18.
//

#include "shared_libraries/entities/ETLevel1.hpp"

ETLevel1::ETLevel1() : AMap(60.0f, 20.0f) {}

void                ETLevel1::init()
{
    this->setLimits();
}

void                ETLevel1::setLimits()
{
    for (float i = 0; i < _length; i += 1.0f)
    {
        _map.insert(std::make_pair(std::unique_ptr<FF::CPosition>(new FF::CPosition(i, 0.0f)), EElement::BORDER));
        _map.insert(std::make_pair(std::unique_ptr<FF::CPosition>(new FF::CPosition(i, 20.0f)), EElement::BORDER));
    }
}