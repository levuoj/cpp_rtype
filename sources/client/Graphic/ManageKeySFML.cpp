#include <iostream>
#include "client/Graphic/ObservableKey.hpp"
#include "client/Graphic/ManageKeySFML.hpp"

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
        case sf::Keyboard::BackSpace:
            this->_key = ObservableKey::Keys::BackSpace;
            break;
        case sf::Keyboard::Period :
            std::cout << "Period" << std::endl;
            this->_key = ObservableKey::Keys::Period;
            break;
        case sf::Keyboard::Num0 :
            this->_key = ObservableKey::Keys::Num0;
            break;
        case sf::Keyboard::Num1 :
            this->_key = ObservableKey::Keys::Num1;
            break;
        case sf::Keyboard::Num2 :
            this->_key = ObservableKey::Keys::Num2;
            break;
        case sf::Keyboard::Num3 :
            this->_key = ObservableKey::Keys::Num3;
            break;
        case sf::Keyboard::Num4 :
            this->_key = ObservableKey::Keys::Num4;
            break;
        case sf::Keyboard::Num5 :
            this->_key = ObservableKey::Keys::Num5;
            break;
        case sf::Keyboard::Num6 :
            this->_key = ObservableKey::Keys::Num6;
            break;
        case sf::Keyboard::Num7 :
            this->_key = ObservableKey::Keys::Num7;
            break;
        case sf::Keyboard::Num8 :
            this->_key = ObservableKey::Keys::Num8;
            break;
        case sf::Keyboard::Num9 :
            this->_key = ObservableKey::Keys::Num9;
            break;
        default:
            this->_key = ObservableKey::Keys::Unknown;
    }
    this->notify();
}
