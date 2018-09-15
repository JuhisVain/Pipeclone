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

    if (input_x != 666) {
      current_level.Play_tile(input_x,input_y);
    } else {
      Test_pipe();
    }
  }
}

void Game::Test_pipe()
{
  crd path_head = current_level.Get_start();
  Field &field = current_level.Get_field();
  int pipecode = (N|E|S|W)&(field.tileat(path_head.x, path_head.y).Get_pipe());

  while (true) {

    std::cout << "crd: " << path_head.x << "," << path_head.y;
    
    switch (pipecode) {
    case N: //Go look at North
      std::cout << ", N" << std::endl;
      --path_head.y;
      pipecode = field.tileat(path_head.x, path_head.y).Get_pipe(); //tile at North
      if ( ((N|E|S|W) & pipecode) == (N|E|S|W)) { //Is a cross?
	std::cout << " Is cross, ";
	pipecode = N & pipecode;
      } else if (S & pipecode) { //Has entry from South?
	std::cout << " Has entry from south" << std::endl;
	pipecode = (N|E|W) & pipecode; //pipecode with exit only
      } else {
	std::cout << "Pipe leaks at (" << path_head.x << "," << path_head.y << ")" << std::endl;
	return;
      }
      break;
    case E:
      std::cout << ", E" << std::endl;
      ++path_head.x;
      pipecode = field.tileat(path_head.x, path_head.y).Get_pipe();
      if ( ((N|E|S|W) & pipecode) == (N|E|S|W)) {
	std::cout << " Is cross, ";
	pipecode = E & pipecode;
      } else if (W & pipecode) {
	std::cout << " Has entry from west" << std::endl;
	pipecode = (N|E|S) & pipecode;
      } else {
	std::cout << "Pipe leaks at (" << path_head.x << "," << path_head.y << ")" << std::endl;
	return;
      }
      break;
    case S:
      std::cout << ", S" << std::endl;
      ++path_head.y;
      pipecode = field.tileat(path_head.x, path_head.y).Get_pipe();
      if ( ((N|E|S|W) & pipecode) == (N|E|S|W)) {
	std::cout << " Is cross, ";
	pipecode = S & pipecode;
      } else if (N & pipecode) {
	std::cout << " Has entry from north" << std::endl;
	pipecode = (S|E|W) & pipecode;
      } else {
	std::cout << "Pipe leaks at (" << path_head.x << "," << path_head.y << ")" << std::endl;
	return;
      }
      break;
    case W:
      std::cout << ", W" << std::endl;
      --path_head.x;
      pipecode = field.tileat(path_head.x, path_head.y).Get_pipe();
      if ( ((N|E|S|W) & pipecode) == (N|E|S|W)) {
	std::cout << " Is cross, ";
	pipecode = W & pipecode;
      } else if (E & pipecode) {
	std::cout << " Has entry from east" << std::endl;
	pipecode = (S|W|N) & pipecode;
      } else {
	std::cout << "Pipe leaks at (" << path_head.x << "," << path_head.y << ")" << std::endl;
	return;
      }
      break;
    default:
      if (field.tileat(path_head.x, path_head.y).Get_pipe() & END) {
	std::cout << "No leak!" << std::endl;
      } else {
	std::cout << "FAIL: " << pipecode << std::endl;
      }
	return;
      break;
    }
    
  }

}
