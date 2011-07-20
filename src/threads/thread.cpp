#include "thread.h"
#include <QDebug>

Thread::Thread(const QString &name, QObject *parent) :
    QThread(parent), m_name(name)
{
}

void Thread::run()
{
  while(1)
  {
    qDebug() << "Hello from " << m_name;
  }
}
