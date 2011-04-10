#include <QtTest/QtTest>
#include <QtCore/QtCore>
#include <QApplication>
#include "test1.h"
#include "test2.h"


int main(int c, char **v)
{
  QApplication app(c,v);

  SummatorTest t1;
  TestForm t2;

  QTest::qExec(&t1);
  QTest::qExec(&t2);
}

