#include <iostream>
#include "field.hpp"
#include "tile.hpp"
#include "common_data_fun.hpp"

Field::Field()
  :width(0), height(0)
{}

Field::Field(int width, int height)
  :width(width), height(height)
{
  for (int y = 0; y < height; ++y) {
    for (int x = 0; x < width; ++x) {
      field.push_back(Tile(0));
    }
  }

  std::cout << "\n Created field:" << std::endl;
  for (int y = 0; y < height; ++y) {
    for (int x = 0; x < width; ++x) {
      std::cout << tileat(x,y).Get_pipe() << " : ";
    }
    std::cout << std::endl;
  }
}

Tile Field::tileat(int x, int y)
{
  return field[x + width*y];
}

int Field::Get_width()
{
  return width;
}
int Field::Get_height()
{
  return height;
}

void Field::Set_tile(int x, int y, int pipe)
{
  field[x + width*y].Set_pipe(pipe);
}

void Field::Set_tile(int x, int y, Tile tile)
{
  field[x + width*y] = tile;
}
