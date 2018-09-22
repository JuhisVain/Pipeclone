#include <iostream>
#include "level.hpp"
#include "common_data_fun.hpp"

//Public

Level::Level(int difficulty, int level_count)
  :difficulty(difficulty),
   level_count(level_count),
   time_before_start(0),
   score(0),
   field(Generate_field(difficulty, level_count)),
   tile_queue_size(8)
{
  std::cout << "level constructor" << std::endl;
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

Tile *Level::Get_tile_ref(int index)
{
  return &(tile_queue[index]);
}

int Level::Get_tile_queue_size()
{
  return tile_queue_size;
}

Field &Level::Get_field()
{
  return field;
}

void Level::Play_tile(int x, int y)
{
  if (field.tileat(x,y).Invulnerable()) {
    std::cout << "Invulnerable clicked: " << x << "," << y << std::endl;
  } else {
    std::cout << "OK clicked: " << x << "," << y << std::endl;
    field.Set_tile(x,y,Pop_tile());
    //Play_tile(x,y); I'm a moron
  }
}

struct coordinates Level::Get_start()
{
  return start_tile;
}

//Private

Field Level::Generate_field(int difficulty, int level_count)
{
  //TODO: check that start and end don't point to walls
  int width = 10, height = 7;
  Field field = Field(width,height);


  //Create start and end tiles:
  int startx = (randint() % width);
  int starty = (randint() % height);

  std::cout << "startx : " << startx << "starty : " << starty << std::endl;
  
  field.Set_tile(startx, starty, GODMODE|START|(0x1<<(randint()%4)));
  
  start_tile.x = startx;
  start_tile.y = starty;

  flood_head.x = -1;
  flood_head.y = -1;
  
  int endx, endy;
  do {
    endx = (randint() % width);
    endy = (randint() % height);
  } while(endx == startx && endy == starty);
  field.Set_tile(endx, endy, GODMODE|END|(0x1<<(randint()%4)));

  std::cout << "Generate field finished, returining" << std::endl;

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
