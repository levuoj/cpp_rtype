//
// Created by pashervz on 13/01/18.
//

#include <server/AMap.hpp>
#include <server/EventMap.hpp>
#include <sstream>
#include <iomanip>
#include "server/GameSession.hpp"

void            FF::GameSession::sendMap()
{
    Event    event;
    std::stringstream stream;

    event.type = EventType::SENDING_MAP;
    event.subType = SubType::FROMSERVER;

    for (const auto & it : this->getEntity<AMap>(0)->getMap())
    {
        stream.str("");
        stream.clear();
        stream << std::fixed << std::setprecision(3) << it.first->getX();
        event.datas.push_back(stream.str());
        stream.str("");
        stream.clear();
        stream << std::fixed << std::setprecision(3) << it.first->getY();
        event.datas.push_back(stream.str());
        event.datas.push_back(std::to_string(it.second.first));

        //event.mapPacket.insert(Coords<float>(it.first.get()->getX(), it.first.get()->getY()), it.second.first);
    }
    this->_function(event);
}

void            FF::GameSession::startGame()
{
    this->insert<MAP>();
    this->insert<PLAYER>();
    this->insert<BASICMONSTER>();
    this->getEntity<AMap>(0)->putElem((*getEntity<APlayer>(1)->getPositon()), EElement::PLAYER, 1);
    this->getEntity<AMap>(0)->putElem((*getEntity<APlayer>(2)->getPositon()), EElement::BASICMONSTER, 2);
    this->getEntity<AMap>(0)->displayMap();
    this->getEntity<APlayer>(1)->setDirection(EMoveType::FORWARD);
    for (auto & it : _systems)
    {
        it.second->execute();
    }
    this->getEntity<AMap>(0)->displayMap();
    this->sendMap();
}

