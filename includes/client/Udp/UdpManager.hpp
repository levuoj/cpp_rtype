//
// Created by daze on 09/01/18.
//

#ifndef CPP_RTYPE_UDPMANAGER_HPP
#define CPP_RTYPE_UDPMANAGER_HPP

#include "client/AManager.hpp"
#include "client/Udp/UdpSocket.hpp"
#include <memory>

    class UdpManager : public AManager {

    private:
        std::shared_ptr<UdpSocket>    _socket;

    public:
        UdpManager(Mediator&);

        virtual ~UdpManager() = default;

        void connectSocket(Event const&);
        virtual void receive(Event const &);
        void notifyFromSocket(Event const &);
    };


#endif //CPP_RTYPE_UDPMANAGER_HPP
