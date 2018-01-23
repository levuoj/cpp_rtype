//
// Created by daze on 09/01/18.
//

#include "client/Udp/UdpSocket.hpp"
#include <iostream>
#include <QtCore/QDataStream>
#include <cstring>
#include <QtCore/QDebug>

namespace   Client {
    UdpSocket::UdpSocket(std::function<void(Event const &)> const &notifyFunc) : _socket(nullptr),
                                                                                 _notifyFunc(notifyFunc) {
    }

    void UdpSocket::bindSocket() {
        _socket = std::make_unique<QUdpSocket>(this);
        if (_socket->bind(QHostAddress::Any, 1025) == false)
            throw (std::runtime_error("Can't bind"));
        connect(_socket.get(), SIGNAL(readyRead()), this, SLOT(readyRead()));
        _actualIp = QHostAddress("127.0.0.1");


        /*QByteArray packet;

        unsigned short r = 220;
        std::string s1 = "Myriom";
        std::string s2 = "Choleil";
        char c = '\0';
        std::string data = s1 + '\0' + s2;


        packet = QByteArray(reinterpret_cast<const char *>(&r), sizeof(r));
        packet.append(s1.c_str());
        packet.append(c);
        packet.append(s2.c_str()); */

        Event test;

        test.type = EventType::STARTGAME;
        test.datas.push_back("lol");
        test.datas.push_back("mdrrrrr");

        writePacket(ProtocolHandler::EventToByteArray(test));
    }

    void UdpSocket::setIp(std::string const &) {
        //_actualIp = QHostAddress(ipAddr.data());
    }

    void UdpSocket::disconnectSocket() {
        if (_socket != nullptr) {
            _socket->close();
            _socket = nullptr;
        }
    }

    void UdpSocket::writePacket(QByteArray packet) {
        if (_socket == nullptr)
            return;

        qDebug() << "WRITE = " << packet;
        _socket->writeDatagram(packet, _actualIp, 1024);
    }

    void UdpSocket::readyRead() {
        QByteArray buffer;
        buffer.resize(_socket->pendingDatagramSize());

        QHostAddress sender;
        quint16 senderPort;

        _socket->readDatagram(buffer.data(), buffer.size(),
                              &sender, &senderPort);

        qDebug() << "READ = " << buffer;
        std::cout << buffer.data() << std::endl;
        Event event = ProtocolHandler::ByteArrayToEv(buffer);
        _notifyFunc(event);
    }

}