#include <iostream>

#include "main_window.hpp"
#include "controller.hpp"

extern Controller *ctrl;

//public:
Main_window::Main_window(QWidget *parent)
  : QMainWindow(parent),
    central_widget(new QWidget(this)),
    ui_field(new Ui_playfield(central_widget, ctrl->Get_field())),
    ui_panel(new Ui_panel(central_widget, ctrl->Get_level()))
{
  std::cout << "mw construct" << std::endl;
  Setup_ui();
}

//public slots:
void Main_window::update_panel()
{
  std::cout << "mw.update_panel" << std::endl;
  ui_panel->panel_update();
}

//private:
void Main_window::Setup_ui()
{
  std::cout << "setupui" << std::endl;
  this->resize(800,600);
  this->setCentralWidget(central_widget);
  //ui_field->resize(640,480);
  ui_field->setGeometry(128,16,640,480);
  ui_field->repaint();

  ui_panel->setGeometry(16,16,96,512);

  std::cout << "update tile queuq" << std::endl;
  ui_panel->update_tile_queue();
  std::cout << "repaint:" << std::endl;
  ui_panel->repaint();
  std::cout << "repaint done" << std::endl;

  QObject::connect(ui_field, SIGNAL(field_clicked()), this, SLOT(update_panel()));

  std::cout << "qt connect done" << std::endl;
  
}
