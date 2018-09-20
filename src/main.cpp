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
  
  std ::cout << "Some random number for your viewing pleasure:" << std::endl
	     << randint() << ", " << randint() << ", " << randint() << std::endl;

  QApplication app(argc, argv);
  Main_window mw(NULL);

  std::cout << "Main window created" << std::endl;

  mw.show();

  std::cout << "main window shown" << std::endl;
  
  return app.exec();
  //Game game(0);
}
