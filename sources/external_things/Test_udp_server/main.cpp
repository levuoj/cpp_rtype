//
// main.cpp for  in /home/levuoj/rendu/cpp_rtype/sources/external_things/Test_udp_server
//
// Made by levuoj
// Login   <anthony.jouvel@epitech.eu>
//
// Started on  Tue Jan  9 14:30:19 2018 levuoj
// Last update Tue Jan  9 14:32:21 2018 levuoj
//

#include <exception>
#include <iostream>
#include <boost/lexical_cast.hpp>
#include "external_things/Test_udp_server/server.hpp"

int main(int ac, char **av)
{
    if (ac != 2) {
        std::cerr << "Usage : " << av[0] << " [port]" << std::endl;
        return (-1);
    }
    try {
        boost::asio::io_service io_service;
        udp_server server(io_service, boost::lexical_cast<unsigned short>(av[1]));
        io_service.run();
        std::cout << "Anthony" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}