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
  this->tile = tile;
}

int Ui_tile::dbpipe()
{
  return tile->Get_pipe();
}

//protected:
void Ui_tile::paintEvent(QPaintEvent *event)
{
  QPainter painter(this);
  
  painter.setPen(Qt::black);

  painter.eraseRect(0,0,64,64);
  
  int pipecode = tile->Get_pipe();

  std::cout << " pc: " << pipecode
	    << " has goo: " << (pipecode&HAS_GOO) << std::endl;

  if (pipecode) { //center
    painter.drawEllipse(28,28,8,8);
  }

  if (pipecode&START) {
    painter.drawText(4,20,QString("S"));
  } else if (pipecode&END) {
    painter.drawText(4,20,QString("E"));
  }

  if (pipecode&HAS_GOO) {
    painter.drawText(50,20,QString("G"));
  }

  for (int i = 0; i < 2; ++i) {
    if ((pipecode & (N|E|S|W)) == (N|E|S|W)) {
      painter.fillRect(28,0,8,64,Qt::black);
      painter.fillRect(0,28,64,8,Qt::black);
      goto forescape;
    } else if(pipecode & N) {
      painter.fillRect(28,0,8,32,Qt::black);
      pipecode &= ~N;
    } else if (pipecode & S) {
      painter.fillRect(28,32,8,32,Qt::black);
      pipecode &= ~S;
    } else if (pipecode & W) {
      painter.fillRect(0,28,32,8,Qt::black);
      pipecode &= ~W;
    } else if (pipecode & E) {
      painter.fillRect(32,28,32,8,Qt::black);
      pipecode &= ~E;
    } else {
      painter.drawRect(10,10,32,32);
      goto forescape;
    } //ifelse
  } //for
 forescape:
  return;
  
}
