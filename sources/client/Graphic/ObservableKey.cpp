//
// ObservableKey.cpp for ObservableKey in /home/pashervz/Epitech/C++/Arcade/cpp_arcade/header
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Sat Apr  1 18:45:59 2017 Pashervz
// Last update Fri Apr  7 10:17:20 2017 Pierre Zawadil
//

#include "client/Graphic/ObservableKey.hpp"

ObservableKey::ObservableKey() : _key(ObservableKey::Keys::Unknown), _isFinished(false) {}

ObservableKey::Keys		ObservableKey::getKey() const
{
  return (this->_key);
}

void				ObservableKey::finish()
{
  this->_isFinished = true;
}

bool				ObservableKey::getFinished() const
{
  return (this->_isFinished);
}
