#include <iostream>
#include "game.hpp"

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
	std::cout << field.tileat(w,h).Get_pipe() << " : ";
      }
      std::cout << std::endl;
    }
    std::cout << "Tile queue: ";
    for (unsigned int i = 0; i < tq.size(); ++i) {
      std::cout << tq[i].Get_pipe() << "; ";
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

