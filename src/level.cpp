#include <iostream>
#include "level.hpp"
#include "common_data_fun.hpp"

//Public

Level::Level(int difficulty, int level_count)
  :difficulty(difficulty),
   level_count(level_count),
   time_before_start(0),
   score(0),
   field(Generate_field(difficulty, level_count))
{
  Generate_tile_queue(difficulty,level_count);
}

Tile Level::Pop_tile()
{
  Tile popped = tile_queue.front();
  tile_queue.pop_front();
  Generate_tile(difficulty,level_count);
  std::cout << "Tile popped: " << popped.Get_pipe() << std::endl;
  return popped;
}

std::deque<Tile> &Level::Get_tile_queue()
{
  return tile_queue;
}

Field &Level::Get_field()
{
  return field;
}

void Level::Play_tile(int x, int y)
{
  field.Set_tile(x,y,Pop_tile());
}

//Private

Field Level::Generate_field(int difficulty, int level_count)
{
  int width = 16, height = 16, wrap = 0; //Todo fun's args should affect
  Field field = Field(width,height,wrap);

  //Create start and end tiles:
  int startx = (randint() % width);
  int starty = (randint() % height);
  field.Set_tile(startx, starty, START|(0x1<<(randint()%4)));
  int endx, endy;
  do {
    endx = (randint() % width);
    endy = (randint() % height);
  } while(endx == startx && endy == starty);
  field.Set_tile(endx, endy, END|(0x1<<(randint()%4)));

  return field;
}

void Level::Generate_tile(int difficulty, int level_count)
{
  tile_queue.push_back(Tile());
}

void Level::Generate_tile_queue(int difficulty, int level_count)
{
  //diff and lc might be used to determine how many tiles in queue are visible aka. exist
  for (int i = 0; i < 8; ++i) {
    Generate_tile(difficulty, level_count);
  }
}