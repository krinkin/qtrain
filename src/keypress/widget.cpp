#include "widget.h"
#include <QVBoxLayout>
#include <QDebug>


Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
  setLayout(new QVBoxLayout());
  m_label = new QLabel("",this);
  layout()->addWidget(m_label);
  connect(this, SIGNAL(keysChanged()),this, SLOT(updateLabel()));
  emit keysChanged();
}


void Widget::keyPressEvent(QKeyEvent *ke)
{
  m_keys.insert(ke->key());
  emit keysChanged();
}

void Widget::keyReleaseEvent(QKeyEvent *ke)
{
    m_keys.remove(ke->key());
    emit keysChanged();
}

void Widget::updateLabel()
{
  QString s="Keys pressed: ";
  char c;
  foreach(c,m_keys)
    s+=c;
  m_label->setText(s);
}

