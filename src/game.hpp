#ifndef GAME_H
#define GAME_H

#include "level.hpp"

class Game
{
public:
  explicit Game(int difficulty);
  
private:
  int difficulty;
  int total_score;
  int level_count;
  Level current_level;

};

#endif
