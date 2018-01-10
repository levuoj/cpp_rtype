#include <iostream>
#include "client/SfmlWindow.hpp"
#include <SFML/Graphics.hpp>
#include <QtCore/QCoreApplication>
#include <client/Mediator.hpp>

int main(int argc, char **argv)
{
    Client::SfmlWindow window;
    QCoreApplication app(argc, argv);

    Mediator med;

    window.startGame();

    app.exec();
    return 0;
}