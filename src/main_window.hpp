#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>

#include "ui_playfield.hpp"

class Main_window : public QMainWindow
{
  Q_OBJECT
public:
  explicit Main_window(QWidget *parent = 0);

private:
  void Setup_ui();

  QWidget *central_widget;
  Ui_playfield *ui_field;

  
  
};

#endif
