//
// Created by daze on 09/01/18.
//

#include "client/Udp/UdpManager.hpp"

UdpManager::UdpManager(Mediator &m) : AManager(m)
{
    auto fp = std::bind(&UdpManager::notifyFromSocket, this, std::placeholders::_1);
    _socket = std::shared_ptr<UdpSocket>(new UdpSocket(fp));
    _socket->bindSocket();
}

void    UdpManager::notifyFromSocket(Event const &ev)
{
    sending(ev);
}

void    UdpManager::connectSocket(Event const &)
{
    _socket->bindSocket();
}

void    UdpManager::receive(Event const &ev)
{
    if (ev.subType == SubType::FROMCLIENT) // TREAT EVENT FROM CLIENT ONLY
    {

        switch (ev.type)
        {
            case EventType::NEWGAME:
                break;
            case EventType::JOINGAME:
                break;
            case EventType::QUITGAME:
                break;
            case EventType::INPUT:
                break;
            default:
                break;
        }

    }
}