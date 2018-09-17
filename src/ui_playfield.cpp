#include "ui_playfield.hpp"
#include <iostream>

#include "game.hpp"

extern Controller *ctrl;

//public::
Ui_playfield::Ui_playfield(QWidget *parent, Field &datafield)
  : QWidget(parent),
    playfield(datafield),
    tilesize(64)
{
  Setup_ui_field();
}

//protected:
void Ui_playfield::mouseReleaseEvent(QMouseEvent *event)
{
  int xcoord = event->x()/tilesize;
  int ycoord = event->y()/tilesize;

  playfield.Set_tile(xcoord,ycoord,ctrl->Get_game().Get_level().Pop_tile());
  ui_tiles[xcoord+playfield.Get_width()*ycoord]->repaint();
  
  
}

//private:
void Ui_playfield::Setup_ui_field()
{
  for (int y = 0; y < playfield.Get_height(); ++y) {
    for (int x = 0; x < playfield.Get_width(); ++x) {
      Ui_tile *tile = new Ui_tile(this, playfield.tileat(x,y));
      ui_tiles.push_back(tile);
      std::cout << print_pipe(tile->dbpipe());
      tile->setGeometry(x*tilesize, y*tilesize, tilesize, tilesize);
    }
    std::cout << std::endl;
  }
  
  
}
