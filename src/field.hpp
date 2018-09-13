#ifndef FIELD_H
#define FIELD_H

#include <memory>
#include <vector>
#include "tile.hpp"

class Field
{
public:
  Field();
  Field(int width, int height, bool wrap);
  Tile tileat(int x, int y);
  int Get_width();
  int Get_height();

  void Set_tile(int x, int y, int pipe);
  void Set_tile(int x, int y, Tile tile);

private:
  int width, height;
  bool wrap;
  std::vector<Tile> field;
  
};

#endif
