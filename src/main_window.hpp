#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>

#include "ui_playfield.hpp"
#include "ui_panel.hpp"

class Main_window : public QMainWindow
{
  Q_OBJECT
public:
  explicit Main_window(QWidget *parent = 0);
  Ui_playfield *Get_ui_playfield();

public slots:
  void update_panel();

private:
  void Setup_ui();

  QWidget *central_widget;
  Ui_playfield *ui_field;
  Ui_panel *ui_panel;

  
  
};

#endif
