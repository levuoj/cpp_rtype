//
// ManageKeySFML.cpp for arcade in /home/zawadi_p/rendu/CPP/cpp_arcade/sources/SFML
// 
// Made by Pierre Zawadil
// Login   <pierre.zawadil@epitech.eu>
// 
// Started on  Sat Apr  1 19:24:47 2017 Pierre Zawadil
// Last update Sun Apr  9 19:40:27 2017 Pierre Zawadil
//

#include "ObservableKey.hpp"
#include "ManageKeySFML.hpp"

ManageKeySFML::ManageKeySFML(sf::RenderWindow *window) : _window(window) {}

void			ManageKeySFML::catchKey()
{
  this->_isFinished = false;
  while (!this->_isFinished)
    {
      sf::Event			event;
      while (this->_window->pollEvent(event)
	     && event.type == sf::Event::KeyPressed)
	{
	  switch (event.key.code)
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
	    case sf::Keyboard::Num2:
	      this->_key = ObservableKey::Keys::Num2;
	      break;
	    case sf::Keyboard::Num3:
	      this->_key = ObservableKey::Keys::Num3;
	      break;
	    case sf::Keyboard::Num4:
	      this->_key = ObservableKey::Keys::Num4;
	      break;
	    case sf::Keyboard::Num5:
	      this->_key = ObservableKey::Keys::Num5;
	      break;
	    case sf::Keyboard::Num8:
	      this->_key = ObservableKey::Keys::Num8;
	      break;
	    case sf::Keyboard::Num9:
	      this->_key = ObservableKey::Keys::Num9;
	      break;
	    case sf::Keyboard::Escape:
	      this->_key = ObservableKey::Keys::Escape;
	      break;
	    default:
	      this->_key = ObservableKey::Keys::Unknown;
	    }
	  this->notify();
	}
      this->_key = ObservableKey::Keys::Unknown;
      this->notify();
    }
}
