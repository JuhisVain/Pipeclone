#include "ui_panel.hpp"
#include <iostream>

Ui_panel::Ui_panel(QWidget *parent, Level &level)
  :QWidget(parent),
   level(level),
   tile_queue(this)
{
  std::cout << "ui panel contructor" << std::endl;
  std::deque<Tile> tq = level.Get_tile_queue();
  for (int i = 0; i < tq.size(); ++i) {
    std::cout << "tile_queue[" << i << "] == " << tq[i].Get_pipe() << std::endl;
    Ui_tile *tile = new Ui_tile(tile_queue, level.Get_tile_ref(i));
    std::cout << tile->dbpipe() << std::endl;
    panel_tiles.push_back(tile);
    tile->setGeometry(0, i*64, 64,64);
  }
}

void Ui_panel::panel_update()
{
  std::cout << "uipanel update()" << std::endl;
  update_tile_queue();
  //scores, queue, time... etc
}

void Ui_panel::update_tile_queue()
{
  std::cout << "UPDATE TILE QUEUE" << std::endl;
  std::deque<Tile> &queue_data = level.Get_tile_queue();
  std::cout << "update_tile_queue  ... ";
  std::cout << "queue size : " << queue_data.size() << std::endl;
  for (int i = 0; i < queue_data.size(); ++i) {
    std::cout << "i:" << i << ", " << std::endl;
    panel_tiles[i]->relink_tile(level.Get_tile_ref(i));
  }
  std::cout << " update DONE, now repaint!" << std::endl;
  tile_queue->repaint();
  std::cout << "done!" << std::endl;
}
