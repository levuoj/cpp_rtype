#include <utils/Loader.hpp>
#include <boost/asio/io_service.hpp>
#include "server/UdpServer.hpp"

int main() {
    Mediator mediator;
    /*Loader<Test> loader("./lib/libTest.so");

    loader.Open();
    loader.Load("entryPoint");
    loader.getInstance()->helloWorld();*/
    try
    {
        boost::asio::io_service io_service;
        Server::UdpServer server(mediator, io_service);
        io_service.run();
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}