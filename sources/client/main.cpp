#include <iostream>
#include "client/Graphic/SfmlWindow.hpp"
#include <SFML/Graphics.hpp>
#include <QtCore/QCoreApplication>
#include <client/Mediator.hpp>

int main(int argc, char **argv)
{
    Client::SfmlWindow window;
    QCoreApplication app(argc, argv);

    Client::Mediator med;

    window.startGame();

    app.exec();
    return 0;
}