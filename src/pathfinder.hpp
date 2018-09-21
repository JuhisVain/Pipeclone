#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <thread>
#include <chrono>
#include <iostream>

#include "field.hpp"
#include "level.hpp"

class Timer
{
public:
  void Start();
  void Set_interval(int milliseconds);
  std::thread *Create_thread();
  
private:
  bool running = false;
  int ms_interval = 10000;
  
};

class Pathfinder
{
public:
  Pathfinder();
  void Start_timer();
  
private:
  Timer timer;
  std::thread *timer_th;

};

#endif
