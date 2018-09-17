#include "ui_tile.hpp"
#include <iostream>

//public:
Ui_tile::Ui_tile(QWidget *parent, Tile &tile)
  :QWidget(parent),
   tile(tile)
{
}

int Ui_tile::dbpipe()
{
  return tile.Get_pipe();
}

//protected:
void Ui_tile::paintEvent(QPaintEvent *event)
{
  QPainter painter(this);
  
  painter.setPen(Qt::black);

  painter.eraseRect(0,0,64,64);
  
  int pipecode = tile.Get_pipe();
  //std::cout <<  "tile num: " << pipecode << std::endl;

  if (pipecode )painter.drawEllipse(28,28,8,8); //center

  for (int i = 0; i < 2; ++i) {
    if ((pipecode & (N|E|S|W)) == (N|E|S|W)) {
      //std::cout << "cross" << std::endl;
      painter.drawRect(28,0,8,64);
      painter.drawRect(0,28,64,8);
      goto forescape;
    } else if(pipecode & N) {
      //std::cout << "N" << std::endl;
      painter.drawRect(28,0,8,32);
      pipecode &= ~N;
    } else if (pipecode & S) {
      //std::cout << "S" << std::endl;
      painter.drawRect(28,32,8,32);
      pipecode &= ~S;
    } else if (pipecode & W) {
      //std::cout << "W" << std::endl;
      painter.drawRect(0,28,32,8);
      pipecode &= ~W;
    } else if (pipecode & E) {
      //std::cout << "E" << std::endl;
      painter.drawRect(32,28,32,8);
      pipecode &= ~E;
    } else {
      //std::cout << "ERROR" << std::endl;
      painter.drawRect(0,0,64,64);
    } //ifelse
  } //for
 forescape:
  return;
  
}
