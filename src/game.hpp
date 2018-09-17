#ifndef GAME_H
#define GAME_H

#include "level.hpp"

std::string print_pipe(int pipe);

class Game
{
public:
  explicit Game(int difficulty);
  Level &Get_level();
  Field &Get_field();
  
private:
  int difficulty;
  int total_score;
  int level_count;
  Level current_level;

  void Test_pipe();

};

#endif
