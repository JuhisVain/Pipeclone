#ifndef UI_PANEL_H
#define UI_PANEL_H

#include <QWidget>
#include "ui_tile.hpp"
#include "level.hpp"

class Ui_panel : public QWidget
{
  Q_OBJECT

public:
  Ui_panel(QWidget *parent, Level &level);
  void panel_update();
  void update_tile_queue();

private:
  Level &level;
  std::vector<Ui_tile*> panel_tiles;
  QWidget *tile_queue;
  
};

#endif
