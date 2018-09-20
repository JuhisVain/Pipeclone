#include "controller.hpp"
#include <iostream>

Controller::Controller()
  : game(0)
{}

void Controller::New_game(int difficulty)
{
  std::cout << "New_game(" << difficulty << ")" << std::endl; 
  game = Game(difficulty);
}

Field &Controller::Get_field()
{
  std::cout << "Get_field()" << std::endl;
  return game.Get_field();
}

Level &Controller::Get_level()
{
  return game.Get_level();
}

Game &Controller::Get_game()
{
  return game;
}
