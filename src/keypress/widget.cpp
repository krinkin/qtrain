#include "widget.h"
#include <QVBoxLayout>


Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
  setLayout(new QVBoxLayout());
  m_label = new QLabel(":",this);
  layout()->addWidget(m_label);
}

void Widget::keyPressEvent(QKeyEvent *ev)
{
  QString s("pressed:");
  s+=ev->key();
  bool p=(ev->type() == QEvent::KeyPress);
  bool r=(ev->type() == QEvent::KeyRelease);
  s+=(p?"1":"0");
  s+=(r?"1":"0");
  m_label->setText(s);
}
