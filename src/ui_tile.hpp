#ifndef UI_TILE_H
#define UI_TILE_H

#include <QWidget>
#include <QPainter>
#include "tile.hpp"

class Ui_tile : public QWidget
{
  Q_OBJECT
public:
  Ui_tile(QWidget *parent, Tile &tile);

  int dbpipe();
  
protected:
  virtual void paintEvent(QPaintEvent *event);
  
private:
  Tile &tile;
};

#endif
