//
// Created by daze on 09/01/18.
//

#ifndef CPP_RTYPE_UDPSOCKET_HPP
#define CPP_RTYPE_UDPSOCKET_HPP

#include "utils/Event.hpp"
#include "ProtocolHandler.hpp"
#include "IudpSocket.hpp"
#include <QObject>
#include <QUdpSocket>
#include <memory>

namespace   Client
{
    class UdpSocket : public QObject, public IudpSocket {

    private:
        std::unique_ptr<QUdpSocket> _socket;
        QHostAddress _actualIp;
        int _actualPort;
        std::function<void(Event const &)> _notifyFunc;


    Q_OBJECT
    public:
        UdpSocket(std::function<void(Event const &)> const &);


        virtual void bindSocket();
        void disconnectSocket();

        virtual void writePacket(Event const &);

        void setIp(std::string const &);

    signals:

    public slots:

        virtual void readyRead();

    };
}
#endif //CPP_RTYPE_UDPSOCKET_HPP