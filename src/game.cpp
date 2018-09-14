#include <iostream>
#include "game.hpp"

//Testing without gui:
std::string print_pipe(int pipe)
{
  std::string draw;
  switch (pipe) {
  case (0):
    draw = ".";
    break;
  case (N|S):
    draw = "\u2503";
    break;
  case (W|E):
    draw = "\u2501";
    break;
  case (N|E):
    draw = "\u2517";
    break;
  case (N|W):
    draw = "\u251B";
    break;
  case (S|E):
    draw = "\u250F";
    break;
  case (S|W):
    draw = "\u2513";
    break;
  case (N|E|S|W):
    draw = "\u254B";
    break;
  case (START|N):
    draw = "\u2579";
    break;
  case (START|E):
    draw = "\u257A";
    break;
  case (START|S):
    draw = "\u257B";
    break;
  case (START|W):
    draw = "\u2578";
    break;
  case (END|N):
    draw = "\u255C";
    break;
  case (END|E):
    draw = "\u2558";
    break;
  case (END|S):
    draw = "\u2553";
    break;
  case (END|W):
    draw = "\u2555";
    break;
  default:
    draw = "?";
    break;
  }

  return draw;
}

Game::Game(int difficulty)
  :difficulty(difficulty),
   total_score(0),
   level_count(0),
   current_level(Level(difficulty,level_count))
{

  //this is a test:
  Field &field = current_level.Get_field();
  std::deque<Tile> &tq = current_level.Get_tile_queue();
  int fw = field.Get_width();
  int fh = field.Get_height();
  
  while (true) {
    for (int h = 0; h < fh; ++h) {
      for (int w = 0; w < fw; ++w) {
	std::cout << print_pipe(field.tileat(w,h).Get_pipe());
      }
      std::cout << std::endl;
    }
    std::cout << "Tile queue: ";
    for (unsigned int i = 0; i < tq.size(); ++i) {
      std::cout << print_pipe(tq[i].Get_pipe()) << "; ";
    }
    std::cout << std::endl;

    int input_x, input_y;
    std::cout << "Give X: ";
    std::cin >> input_x;
    std::cout << "Give Y: ";
    std::cin >> input_y;

    current_level.Play_tile(input_x,input_y);
    
    
  }
  
}

