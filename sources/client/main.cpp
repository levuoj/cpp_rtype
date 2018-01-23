#include <iostream>
#include "client/Graphic/SfmlWindow.hpp"
#include <QtCore/QCoreApplication>
#include <utils/Mediator.hpp>
#include <thread>
#include "client/Graphic/GraphicManager.hpp"

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);
    try {
        QCoreApplication app(argc, argv);

        //window.startGame();

        Mediator med;
        med.addManager(new Client::GraphicManager(med));
        std::thread t([&med]() {
            med.launch();
        });
        app.exec();
        t.join();


    }
    catch(std::exception &e)
    {
        std::cout << "EXCEPTION POP = " << e.what() << std::endl;
    }
    return 0;
}