//
// Observable.hpp for Observable in /home/pashervz/Epitech/C++/Arcade/cpp_arcade/header
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Mon Mar 27 10:40:09 2017 Pashervz
// Last update Sat Apr  1 17:09:23 2017 Pashervz
//

#ifndef OBSERVABLE_HPP_
# define OBSERVABLE_HPP_

#include <memory>
#include "State.hpp"

class AObserver;

class Observable
{
protected:
  AObserver			*_observer;
public:
  Observable();
  virtual ~Observable();
  void				notify();
  void				setObserver(AObserver *);
};

#endif // OBSERVABLE_HPP_
