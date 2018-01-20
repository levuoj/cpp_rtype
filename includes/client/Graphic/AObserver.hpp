//
// AObserver.hpp for AObserver in /home/pashervz/Epitech/C++/Arcade/cpp_arcade/header
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Wed Mar 29 22:06:00 2017 Pashervz
// Last update Wed Mar 29 23:42:05 2017 Pashervz
//
 
#ifndef AOBSERVER_HPP_
# define AOBSERVER_HPP_

#include "Observable.hpp"

class AObserver
{
public:
  virtual void		actualize(Observable const &) = 0;
  virtual ~AObserver() {}
};

#endif // AOBSERVER_HPP_
