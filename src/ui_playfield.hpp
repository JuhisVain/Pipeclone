#ifndef UI_PLAYFIELD_H
#define UI_PLAYFIELD_H

#include <QWidget>
#include <QPainter>
#include <QMouseEvent>

#include <vector>

#include "ui_tile.hpp"
#include "field.hpp"
#include "controller.hpp"
#include "tile.hpp"

class Ui_playfield : public QWidget
{
  Q_OBJECT
  
public:
  Ui_playfield(QWidget *parent, Field &datafield);

signals:
  void field_clicked();

protected:
  virtual void mouseReleaseEvent(QMouseEvent *event);

private:
  Field &playfield;
  int tilesize;

  std::vector<Ui_tile*> ui_tiles;
  

  void Setup_ui_field();  
  
};

#endif
