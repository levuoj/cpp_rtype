//
// Created by toto on 28/01/18.
//

#ifndef CPP_RTYPE_IUDPSOCKET_HPP
#define CPP_RTYPE_IUDPSOCKET_HPP


class IudpSocket {
public:
    virtual void bindSocket() = 0;
    virtual void writePacket(QByteArray const &) = 0;
    virtual void readyRead() = 0;

    IudpSocket() = default;
    virtual ~IudpSocket() = default;
};


#endif //CPP_RTYPE_IUDPSOCKET_HPP
