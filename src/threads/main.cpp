#include <QApplication>
#include <QStringList>
#include "thread.h"
#include <QThreadPool>
#include "task.h"
#include <QDebug>
#include <QtConcurrentRun>
#include <QtConcurrentFilter>

int f(int a, int b, int c)
{
  qDebug() << "a=" << a;
  return a+b+c;
}

bool keep(const QString& s)
{
  if (s == "1")
    return false;
  return true;
}

void filt()
{
  QStringList l;
  l << "1" << "2" << "3";

  QFuture<void> r=QtConcurrent::filter(l,keep);

  r.waitForFinished();

  qDebug() << l;
}

int main(int cc, char **v)
{
  QApplication app(cc,v);

  QFuture<int> a= QtConcurrent::run(f,1,1,1);
  QFuture<int> b= QtConcurrent::run(f,2,2,2);
  QFuture<int> c= QtConcurrent::run(f,3,3,3);

  filt();


  qDebug() << a.result() << b.result() << c.result();


#if 0
  QStringList sl;

  sl << "first" << "second" << "third";

  QString name;
  foreach(name,sl)
  {
    Thread *t=new Thread(name);
    //QThreadPool::globalInstance()->start(t);
  }
  QThreadPool::globalInstance()->start(new Task());
  QThreadPool::globalInstance()->waitForDone();

  qDebug() << "done";
#endif
  return app.exec();
}
