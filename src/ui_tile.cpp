#include "ui_tile.hpp"
#include <iostream>

//public:
Ui_tile::Ui_tile(QWidget *parent, Tile *tile)
  :QWidget(parent),
   tile(tile)
{
  std::cout << "uitile construct" << std::endl;
}

void Ui_tile::relink_tile(Tile *tile)
{
  std::cout << "relink tile" << std::endl;
  this->tile = tile;
}

int Ui_tile::dbpipe()
{
  std::cout << "dbtile" << std::endl;
  return tile->Get_pipe();
}

//protected:
void Ui_tile::paintEvent(QPaintEvent *event)
{
  std::cout << "paintevent" << std::endl;
  QPainter painter(this);
  
  painter.setPen(Qt::black);

  painter.eraseRect(0,0,64,64);
  
  int pipecode = tile->Get_pipe();
  std::cout <<  "tile num: " << pipecode << std::endl;

  if (pipecode) { //center
    painter.drawEllipse(28,28,8,8);
  }

  for (int i = 0; i < 2; ++i) {
    if ((pipecode & (N|E|S|W)) == (N|E|S|W)) {
      //std::cout << "cross" << std::endl;
      painter.fillRect(28,0,8,64,Qt::black);
      painter.fillRect(0,28,64,8,Qt::black);
      goto forescape;
    } else if(pipecode & N) {
      //std::cout << "N" << std::endl;
      painter.fillRect(28,0,8,32,Qt::black);
      pipecode &= ~N;
    } else if (pipecode & S) {
      //std::cout << "S" << std::endl;
      painter.fillRect(28,32,8,32,Qt::black);
      pipecode &= ~S;
    } else if (pipecode & W) {
      //std::cout << "W" << std::endl;
      painter.fillRect(0,28,32,8,Qt::black);
      pipecode &= ~W;
    } else if (pipecode & E) {
      //std::cout << "E" << std::endl;
      painter.fillRect(32,28,32,8,Qt::black);
      pipecode &= ~E;
    } else {
      //std::cout << "ERROR" << std::endl;
      painter.drawRect(10,10,32,32);
      goto forescape;
    } //ifelse
  } //for
 forescape:
  std::cout << "paintevent done!" << std::endl;
  return;
  
}
