#include <iostream>
#include <QtCore/QCoreApplication>
#include <utils/Mediator.hpp>
#include <thread>

int main(int argc, char **argv)
{
    try {
        QCoreApplication app(argc, argv);
        Mediator med;

        std::thread t2([]()
                       {
                        //  Client::SfmlWindow window;
                        // window.startGame();
                      });
        app.exec();
        t2.join();
    }
    catch (std::exception e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}