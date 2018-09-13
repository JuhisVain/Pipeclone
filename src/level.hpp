#ifndef LEVEL_H
#define LEVEL_H

#include <deque>
#include "tile.hpp"
#include "field.hpp"

class Level
{
public:
  Level(int difficulty, int level_count);
  Tile Pop_tile();
  std::deque<Tile> &Get_tile_queue();
  Field &Get_field();

  void Play_tile(int x, int y);

private:
  int difficulty, level_count;
  int time_before_start;
  int score;
  Field field;
  std::deque<Tile> tile_queue;

  Field Generate_field(int difficulty, int level_count);
  void Generate_tile(int difficulty, int level_count);
  void Generate_tile_queue(int difficulty, int level_count);

};

#endif
