#include <cstdlib>
#include <ctime>

#include <iostream>

#include <QApplication>

#include "game.hpp"
#include "controller.hpp"
#include "main_window.hpp"
#include "common_data_fun.hpp"

Controller *ctrl;

int main(int argc, char *argv[])
{
  srand(time(NULL));

  ctrl = new Controller();

  QApplication app(argc, argv);
  Main_window mw(NULL);

  std::cout << "Main window created" << std::endl;

  mw.show();

  std::cout << "main window shown" << std::endl;

  //ctrl->Get_game().Get_pathfinder().Start_timer();
  
  return app.exec();
  //Game game(0);
}
