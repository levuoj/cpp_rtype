#include <iostream>
#include <SFML/Graphics.hpp>
#include <QtCore/QCoreApplication>
#include <client/Mediator.hpp>

int main(int argc, char* argv[]) {

    QCoreApplication app(argc, argv);

    Mediator med;

    app.exec();
}