#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "field.hpp"
#include "game.hpp"

class Controller
{
public:
  Controller();
  void New_game(int difficulty);
  Field &Get_field();
  Level &Get_level();
  Game &Get_game();

private:
  Game game;
  
};

#endif
