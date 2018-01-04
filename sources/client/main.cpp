#include <iostream>
#include <SFML/Graphics.hpp>

int main(int argc, char* argv[]) {

    /* Code adapted from the SFML 2 "Window" example */

    sf::Window App(sf::VideoMode(800, 600), "myproject");

    while (App.isOpen()) {
        sf::Event Event;
        while (App.pollEvent(Event)) {
            if (Event.type == sf::Event::Closed)
                App.close();
        }
        App.display();
    }
}