//
// ManageKeySFML.hpp for arcade in /home/zawadi_p/rendu/CPP/cpp_arcade
// 
// Made by Pierre Zawadil
// Login   <pierre.zawadil@epitech.eu>
// 
// Started on  Sat Apr  1 19:37:20 2017 Pierre Zawadil
// Last update Sun Apr  9 19:40:18 2017 Pierre Zawadil
//

#ifndef _MANAGE_KEY_SFML_HPP
# define _MANAGE_KEY_SFML_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "ObservableKey.hpp"

class ManageKeySFML : public ObservableKey
{
  sf::RenderWindow	*_window;
public:
  ManageKeySFML(sf::RenderWindow *);
  virtual ~ManageKeySFML() {}
  void	  catchKey(sf::Keyboard::Key);
};

#endif // MANAGE_KEY_SFML_HPP
