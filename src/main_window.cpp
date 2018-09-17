#include <iostream>

#include "main_window.hpp"
#include "controller.hpp"

extern Controller *ctrl;

//public:
Main_window::Main_window(QWidget *parent)
  : QMainWindow(parent),
    central_widget(new QWidget(this)),
    ui_field(new Ui_playfield(central_widget, ctrl->Get_field()))
{
  Setup_ui();
}

//private:
void Main_window::Setup_ui()
{
  this->resize(800,600);
  this->setCentralWidget(central_widget);
  ui_field->resize(640,480);
  std::cout << "AAAAAA" << std::endl;
  ui_field->repaint();
  
}
