#include <QApplication>
#include <QDebug>
#include "chatdialog.h"

int main(int c, char **v)
{
  QApplication a(c,v);

  if(a.argc() != 2)
  {
    qDebug() << "Port must be specified";
    return false;
  }

  ChatDialog d(NULL,QString(v[1]).toInt());
  d.show();

  return a.exec();
}

