#include <iostream>
#include "client/ObservableKey.hpp"
#include "client/ManageKeySFML.hpp"

ManageKeySFML::ManageKeySFML(sf::RenderWindow *window) : _window(window) {}

void			ManageKeySFML::catchKey(sf::Keyboard::Key code)
{
    switch (code)
    {
        case sf::Keyboard::Space:
            this->_key = ObservableKey::Keys::Space;
            break;
        case sf::Keyboard::Left:
            this->_key = ObservableKey::Keys::Left;
            break;
        case sf::Keyboard::Right:
            this->_key = ObservableKey::Keys::Right;
            break;
        case sf::Keyboard::Up:
            this->_key = ObservableKey::Keys::Up;
            break;
        case sf::Keyboard::Down:
            this->_key = ObservableKey::Keys::Down;
            break;
        case sf::Keyboard::Return:
            this->_key = ObservableKey::Keys::Return;
            break;
        case sf::Keyboard::Escape:
            this->_key = ObservableKey::Keys::Escape;
            break;
        default:
            this->_key = ObservableKey::Keys::Unknown;
    }
    this->notify();
}
