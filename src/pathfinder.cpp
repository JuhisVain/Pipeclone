#include "pathfinder.hpp"
#include "controller.hpp"


extern Controller *ctrl;

Pathfinder::Pathfinder()
  :timer(),
   timer_th(timer.Create_thread())
{

}

void Pathfinder::Start_timer()
{
  timer.Start();
}

void Timer::Start()
{
  running = true;
  std::cout << "get level" << std::endl;
  Level &current_level = ctrl->Get_level();
  std::cout << "get field" << std::endl;
  Field &field = ctrl->Get_field();
  std::cout << "get start" << std::endl;
  std::cout << "currentlevel" << &current_level << std::endl;
  crd path_head = current_level.Get_start();
  std::cout << "pipecode" << std::endl;
  int pipecode = (N|E|S|W)&(field.tileat(path_head.x, path_head.y).Get_pipe());
  std::cout << "tileat" << std::endl;
  Tile &tile = field.tileat(path_head.x, path_head.y);

  std::cout << "timer init finished" << std::endl;
  
  while (running) {
    //Goo running within tile:
    std::this_thread::sleep_for(std::chrono::milliseconds(ms_interval));
    //sleep(std::chrono::milliseconds(ms_interval));

    std::cout << "within timer's while" << std::endl;

    //start handling next tile:
    switch (pipecode) {
    case N: //Go look at North
      std::cout << ", N" << std::endl;
      --path_head.y;
      tile = field.tileat(path_head.x, path_head.y);
      tile.Put_goo();
      pipecode = tile.Get_pipe(); //tile at North
      if ( ((N|E|S|W) & pipecode) == (N|E|S|W)) { //Is a cross?
	std::cout << " Is cross, ";
	pipecode = N & pipecode;
      } else if (S & pipecode) { //Has entry from South?
	std::cout << " Has entry from south" << std::endl;
	pipecode = (N|E|W) & pipecode; //pipecode with exit only
      } else {
	std::cout << "Pipe leaks at (" << path_head.x << "," << path_head.y << ")" << std::endl;
	running = false;
	return;
      }
      break;
    case E:
      std::cout << ", E" << std::endl;
      ++path_head.x;
      tile = field.tileat(path_head.x, path_head.y);
      tile.Put_goo();
      pipecode = tile.Get_pipe();
      if ( ((N|E|S|W) & pipecode) == (N|E|S|W)) {
	std::cout << " Is cross, ";
	pipecode = E & pipecode;
      } else if (W & pipecode) {
	std::cout << " Has entry from west" << std::endl;
	pipecode = (N|E|S) & pipecode;
      } else {
	std::cout << "Pipe leaks at (" << path_head.x << "," << path_head.y << ")" << std::endl;
	running = false;
	return;
      }
      break;
    case S:
      std::cout << ", S" << std::endl;
      ++path_head.y;
      tile = field.tileat(path_head.x, path_head.y);
      tile.Put_goo();
      pipecode = tile.Get_pipe();
      if ( ((N|E|S|W) & pipecode) == (N|E|S|W)) {
	std::cout << " Is cross, ";
	pipecode = S & pipecode;
      } else if (N & pipecode) {
	std::cout << " Has entry from north" << std::endl;
	pipecode = (S|E|W) & pipecode;
      } else {
	std::cout << "Pipe leaks at (" << path_head.x << "," << path_head.y << ")" << std::endl;
	running = false;
	return;
      }
      break;
    case W:
      std::cout << ", W" << std::endl;
      --path_head.x;
      tile = field.tileat(path_head.x, path_head.y);
      tile.Put_goo();
      pipecode = tile.Get_pipe();
      if ( ((N|E|S|W) & pipecode) == (N|E|S|W)) {
	std::cout << " Is cross, ";
	pipecode = W & pipecode;
      } else if (E & pipecode) {
	std::cout << " Has entry from east" << std::endl;
	pipecode = (S|W|N) & pipecode;
      } else {
	std::cout << "Pipe leaks at (" << path_head.x << "," << path_head.y << ")" << std::endl;
	running = false;
	return;
      }
      break;
    default:
      if (field.tileat(path_head.x, path_head.y).Get_pipe() & END) {
	std::cout << "No leak!" << std::endl;
      } else {
	std::cout << "FAIL: " << pipecode << std::endl;
      }
      running = false;
      return;
      break;
    }
    Set_interval(tile.Get_tile_duration());
  }
}

std::thread *Timer::Create_thread()
{
  return new std::thread( [this] {Start();});
}

void Timer::Set_interval(int milliseconds)
{
  ms_interval = milliseconds;
}

/*
int main()
{
  Pathfinder p;
  return 0;
}
*/
