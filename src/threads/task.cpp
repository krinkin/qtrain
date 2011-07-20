#include "task.h"
#include <QDebug>

Task::Task() :
    QRunnable()
{
}

void Task::run()
{
  for(int i=0;i<10;++i)
  {
    sleep(2);
    qDebug() << "#######################";
  }
}
