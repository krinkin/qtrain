
#include <QApplication>
#include "mainwindow.h"

int main(int c, char **v)
{
  QApplication a(c,v);

  MainWindow mw;

  mw.show();

  a.exec();
}

