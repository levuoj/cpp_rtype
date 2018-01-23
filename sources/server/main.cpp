#include <server/Systems/SMovement.hpp>
#include <server/Network/UdpServer.hpp>
#include <thread>
#include "utils/Mediator.hpp"

int main()
{
    //try {
        Mediator                med;
        boost::asio::io_service io_service;
        Server::UdpServer       *udpServer = new Server::UdpServer(med, io_service);

        med.addManager(udpServer);
        std::thread t([&io_service]() {
            io_service.run();
            std::cout << "LOL" << std::endl;
        });
        med.launch();
        t.join();

    /*}
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }*/
    return (0);
}