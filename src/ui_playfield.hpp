#ifndef UI_PLAYFIELD_H
#define UI_PLAYFIELD_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QPropertyAnimation>

#include <vector>

#include "ui_tile.hpp"
#include "field.hpp"
#include "level.hpp"
//#include "controller.hpp"
#include "tile.hpp"

class Ui_playfield : public QWidget
{
  Q_OBJECT
  
public:
  Ui_playfield(QWidget *parent, Field &datafield, Level &level);
  void Update_tile(int x, int y);
  void Update_tile_goo(int x,int y,int interval, int start_dir);

signals:
  void field_clicked();

protected:
  virtual void mouseReleaseEvent(QMouseEvent *event);

private:
  Field &playfield;
  Level &level;
  int tilesize;

  std::vector<Ui_tile*> ui_tiles;
  
  void Setup_ui_field();  
  
};

#endif
