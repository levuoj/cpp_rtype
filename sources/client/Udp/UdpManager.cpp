//
// Created by daze on 09/01/18.
//

#include "client/Udp/UdpManager.hpp"

UdpManager::UdpManager(Mediator &m) : AManager(m)
{
    auto fp = std::bind(&UdpManager::notifyFromSocket, this, std::placeholders::_1);
    _socket = std::unique_ptr<UdpSocket>(new UdpSocket(fp));
    _socket->bindSocket();
}

void    UdpManager::notifyFromSocket(Event const &ev)
{
    std::cout << "je passe dans NotifyFromSocket" << std::endl;
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
        _socket->writePacket(ProtocolHandler::EventToByteArray(ev));
    }
}