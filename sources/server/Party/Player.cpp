//
// Created by levuoj on 23/01/18.
//

#include <server/Party/Player.hpp>

Server::Player::Player(std::string const &ipAddress, size_t id) : ip_address_(ipAddress), ID_(id)
{}

std::string const&  Server::Player::getIpAddress() const
{
    return (ip_address_);
}

size_t const&       Server::Player::getPlayerID() const
{
    return (ID_);
}