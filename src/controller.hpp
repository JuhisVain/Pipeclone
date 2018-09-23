#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "ui_playfield.hpp"
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
  void Set_ui_playfield(Ui_playfield *ui_field);
  void Update_ui_tile(int x, int y);
  void Update_ui_tile_goo(int x, int y, int interval, int start_dir);

private:
  Game game;
  Ui_playfield *ui_field;
  
};

#endif
