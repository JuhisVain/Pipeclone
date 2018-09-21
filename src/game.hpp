#ifndef GAME_H
#define GAME_H

#include "level.hpp"
#include "pathfinder.hpp"

std::string print_pipe(int pipe);

class Game
{
public:
  explicit Game(int difficulty);
  Level &Get_level();
  Field &Get_field();
  Pathfinder &Get_pathfinder();
  
private:
  int difficulty;
  int total_score;
  int level_count;
  Level current_level;
  Pathfinder pathfinder;

  void Test_pipe();

};

#endif
