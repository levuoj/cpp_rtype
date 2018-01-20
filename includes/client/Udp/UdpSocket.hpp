//
// Created by daze on 09/01/18.
//

#ifndef CPP_RTYPE_UDPSOCKET_HPP
#define CPP_RTYPE_UDPSOCKET_HPP

#include "utils/Event.hpp"
#include "ProtocolHandler.hpp"
#include <QObject>
#include <QUdpSocket>
#include <memory>

namespace   Client
{
    class UdpSocket : public QObject {

    private:
        std::unique_ptr<QUdpSocket> _socket;
        QHostAddress _actualIp;
        int _actualPort;
        std::function<void(Event const &)> _notifyFunc;


    Q_OBJECT
    public:
        UdpSocket(std::function<void(Event const &)> const &);


        void bindSocket();

        void disconnectSocket();

        void writePacket(QByteArray);

        void setIp(std::string const &);

    signals:

    public slots:

        void readyRead();

    };
}
#endif //CPP_RTYPE_UDPSOCKET_HPP