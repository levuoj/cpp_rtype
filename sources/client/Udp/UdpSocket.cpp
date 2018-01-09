//
// Created by daze on 09/01/18.
//

#include "client/Udp/UdpSocket.hpp"
#include <iostream>
#include <QtCore/QDataStream>
#include <cstring>
#include <QtCore/QDebug>

UdpSocket::UdpSocket(std::function<void(Event const &)> const &notifyFunc) : _socket(nullptr), _notifyFunc(notifyFunc)
{
}

void UdpSocket::bindSocket()
{
    _socket = std::make_unique<QUdpSocket>(this);
    if (_socket->bind(QHostAddress::Any, 1024) == false)
        throw (std::runtime_error("Can't bind"));
    connect(_socket.get(), SIGNAL(readyRead()), this, SLOT(readyRead()));


    struct Packet
    {
        unsigned short r;
        std::string data;
    };
    Packet toWrite;

    QByteArray packet;

    toWrite.data = "je suce";
    toWrite.r = 220;
    packet = QByteArray(reinterpret_cast<const char *>(&toWrite), sizeof(toWrite));

    std::cout << "je suis dans le bindSocket" << std::endl;

    writePacket(packet);
}

void UdpSocket::setIp(std::string const& ipAddr)
{
    _actualIp = QHostAddress(ipAddr.data());
    _actualIp = QHostAddress("localhost");
}

void UdpSocket::disconnectSocket()
{
    if (_socket != nullptr) {
        _socket->close();
        _socket = nullptr;
    }
}

void UdpSocket::writePacket(QByteArray const &packet)
{
    if (_socket == nullptr)
        return ;

    _socket->writeDatagram(packet, _actualIp, 1024);
    std::cout << "JE CROIS SAVOIR" << std::endl;
}

void UdpSocket::readyRead()
{
    QByteArray buffer;
    buffer.resize(_socket->pendingDatagramSize());

    QHostAddress sender;
    quint16 senderPort;

    _socket->readDatagram(buffer.data(), buffer.size(),
                         &sender, &senderPort);

    qDebug() << buffer;
    _notifyFunc(ProtocolHandler::ByteArrayToEv(buffer));
}

