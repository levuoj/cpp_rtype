#include <iostream>
#include "client/Graphic/SfmlWindow.hpp"
#include <SFML/Graphics.hpp>
#include <server/ASystem.hpp>
#include <QtCore/QCoreApplication>
#include <utils/Mediator.hpp>

int main(int argc, char **argv)
{
    Client::SfmlWindow window;
    QCoreApplication app(argc, argv);

    Mediator med;

    window.startGame();

    app.exec();
    return 0;
}