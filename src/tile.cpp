#include <iostream>
#include "tile.hpp"
#include "common_data_fun.hpp"

Tile::Tile()
{
  //Dumb tile generator:
  int xyz = randint() % 7;
  switch (xyz) {
  case 0:
    pipe = N|S; //vertical
    break;
  case 1:
    pipe = W|E; //horizontal
    break;
  case 2:
    pipe = N|E; //turns
    break;
  case 3:
    pipe = N|W;
    break;
  case 4:
    pipe = S|E;
    break;
  case 5:
    pipe = S|W;
    break;
  case 6:
    pipe = N|E|S|W; //cross
    break;
  default:
    std::cout << "Tile rand generation failure: " << xyz << std::endl;
    exit(-1);
    break;
  }
}

Tile::Tile(int pipe)
  :pipe(pipe),
   has_goo(false)
{}

int Tile::Get_pipe()
{
  return pipe;
}

void Tile::Set_pipe(int pipe)
{
  this->pipe = pipe;
}

void Tile::Put_goo()
{
  has_goo = true;
}

bool Tile::Has_goo()
{
  return has_goo;
}

int Tile::Get_tile_duration()
{
  if (pipe&POOL) {
    return 4000;
  } else {
    return 2000;
  }
}
