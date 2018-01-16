#include <server/Systems/SMovement.hpp>
#include "utils/Mediator.hpp"
#include "server/ASystem.hpp"
#include <utils/Loader.hpp>
#include <boost/asio/io_service.hpp>
#include "server/UdpServer.hpp"

int main()
{
    Mediator        med;

    med.launch();
}