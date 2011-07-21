#ifndef MYTEST_H
#define MYTEST_H
#include <QtTest/QtTest>


class TestQString: public QObject
{
    Q_OBJECT
private slots:
    void sum()
    {
      QFETCH(int,left);
      QFETCH(int,right);
      QFETCH(int,result);

      QCOMPARE(left+right,result);
    }

    void sum_data()
    {
      QTest::addColumn<int>("left");
      QTest::addColumn<int>("right");
      QTest::addColumn<int>("result");

      QTest::newRow("1st")<<1<<2<<3;
      QTest::newRow("2nd")<<-1<<2<<1;
      QTest::newRow("3rd")<<0<<0<<9;

    }

};

#endif // MYTEST_H
