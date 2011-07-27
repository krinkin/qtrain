#ifndef WTEST_H
#define WTEST_H

#include <QLineEdit>
#include <QtTest/QTest>

class WTest : public QObject
{
  Q_OBJECT

private slots:

  void testGui()
  {
    QLineEdit le;
    le.show();

    QTest::keyClicks(&le,"Hello world",Qt::NoModifier,100);
  }
};


#endif // WTEST_H
