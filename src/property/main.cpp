
#include <QApplication>
#include "Test.h"
#include <QDebug>
#include <QVariant>

int main(int c, char **v)
{
  QApplication a(c,v);

  Test t;

  t.setProp(10);

  qDebug() << t.prop();

  t.setProperty("prop",QVariant(15));

  qDebug() << t.prop();

  return a.exec();
}
