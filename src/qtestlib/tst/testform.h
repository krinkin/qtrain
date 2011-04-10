#ifndef TEST2_H
#define TEST2_H

#include <QObject>
#include <QtTest/QtTest>
#include <QTest>
#include <QSignalSpy>

#include "../app/summatorform.h"

class TestForm : public QObject
{
  Q_OBJECT;

  SummatorForm *m_form;

public:
  TestForm()
  {
    m_form = new SummatorForm(10,20,NULL);
  }

  ~TestForm()
  {
    delete m_form;
  }

private slots:
  void sumgui()
  {
    QSignalSpy spy(m_form->m_summator, SIGNAL(valueChanged()));

    m_form->m_x->setText("30");
    m_form->m_y->setText("90");
    QTest::mouseClick(m_form->m_update,Qt::LeftButton);

    QCOMPARE(spy.count(), 2);
    QCOMPARE(m_form->m_sum->text().toInt(), 120);
  }

};


#endif // TEST2_H
