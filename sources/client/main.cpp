#include <iostream>
#include "client/SfmlWindow.hpp"

int main(int argc, char *argv[])
{
    Client::SfmlWindow *window = new Client::SfmlWindow();

    window->startGame();
    return 0;
}