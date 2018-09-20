#ifndef FIELD_H
#define FIELD_H

#include <memory>
#include <vector>
#include "tile.hpp"


typedef struct coordinates {
  int x, y;
} crd;

class Field
{
public:
  Field();
  Field(int width, int height);
  Tile &tileat(int x, int y);
  Tile *tileptr(int x, int y);
  Tile &Tile_by_index(int i);
  int Get_width();
  int Get_height();

  void Set_tile(int x, int y, int pipe);
  void Set_tile(int x, int y, Tile tile);

private:
  int width, height;
  std::vector<Tile> field;
  
};

#endif
