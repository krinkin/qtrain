#ifndef _TEST1_
#define _TEST1_

#include <QObject>
#include <QtTest/QtTest>
#include <QSignalSpy>

#include "../app/summator.h"

class SummatorTest : public QObject
{
  Q_OBJECT;

  Summator *m_summator;

public:
  SummatorTest()
  {
    m_summator = new Summator(5,13,this);
  }

private slots:
  void sum()
  {
    QCOMPARE(m_summator->sum(),18);
  }

  void changed()
  {
    QSignalSpy spy(m_summator,SIGNAL(valueChanged()));
    m_summator->setX(30);
    m_summator->setY(90);
    QCOMPARE(120,m_summator->sum());
    QCOMPARE(2, spy.count());
  }
};


#endif
