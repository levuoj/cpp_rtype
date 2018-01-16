//
// Created by Oraekia on 13/01/18.
//

#include <server/Components/CPosition.hpp>
#include <server/Components/CVelocity.hpp>
#include <server/Components/CHealth.hpp>
#include <server/Components/CArtificialIntelligence.hpp>
#include "shared_libraries/entities/ETMonster.hpp"

FF::ETMonster::ETMonster() : AMonster()
{
    this->addComponent(std::shared_ptr <AComponent> (new CArtificialIntelligence()));
    this->addComponent(std::shared_ptr <AComponent> (new CPosition()));
    this->addComponent(std::shared_ptr <AComponent> (new CVelocity()));
    this->addComponent(std::shared_ptr <AComponent> (new CHealth()));
}

void        FF::ETMonster::init()
{

}

extern "C"
{
    FF::AMonster        *create()
    {
        return (new FF::ETMonster());
    }
}