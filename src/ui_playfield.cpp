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
  std::cout << "ui_playfield" << std::endl;
  Setup_ui_field();
}

//protected:
void Ui_playfield::mouseReleaseEvent(QMouseEvent *event)
{
  std::cout << "playfield mouse release" << std::endl;
  int xcoord = event->x()/tilesize;
  int ycoord = event->y()/tilesize;

  playfield.Set_tile(xcoord,ycoord,ctrl->Get_game().Get_level().Pop_tile());
  ui_tiles[xcoord+playfield.Get_width()*ycoord]->repaint();

  emit field_clicked();
  
  
}

//private:
void Ui_playfield::Setup_ui_field()
{
  std::cout << "setup ui field " << std::endl;
  for (int y = 0; y < playfield.Get_height(); ++y) {
    for (int x = 0; x < playfield.Get_width(); ++x) {
      Ui_tile *tile = new Ui_tile(this, playfield.tileptr(x,y));
      ui_tiles.push_back(tile);
      std::cout << print_pipe(tile->dbpipe());
      tile->setGeometry(x*tilesize, y*tilesize, tilesize, tilesize);
    }
    std::cout << std::endl;
  }
  
  
}
