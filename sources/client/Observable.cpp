//
// Observable.cpp for Observable in /home/pashervz/Epitech/C++/Arcade/cpp_arcade/sources
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Fri Mar 24 15:23:10 2017 Pashervz
// Last update Sun Apr  9 00:44:24 2017 Pashervz
//

#include <iostream>
#include "client/Observable.hpp"
#include "client/AObserver.hpp"

Observable::Observable() {}

Observable::~Observable() {}

void		Observable::notify()
{
  if (this->_observer)
    this->_observer->actualize(*this);
}

void		Observable::setObserver(AObserver *observer)
{
  this->_observer = observer;
}
