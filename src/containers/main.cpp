#include <QApplication>
#include <QDebug>
#include <QList>
#include <QLinkedList>
#include <QSet>

void qlist()
{
  QList<QString> l;
  QLinkedList<QString> ll;

  l << "1" << "2" << "3";
  ll << "1" << "2" << "3";

  //qDebug() << l[0];

  QLinkedListIterator<QString> li(ll);
  while(li.hasNext())
    qDebug() << li.next();

  //<< ll;

}

void qset()
{
  QSet<QString> s;

  s << "1" << "2" << "1";

  qDebug() << s;


  QSetIterator<QString> si(s);
  while (si.hasNext())
    qDebug() << si.next();

}

int main(int c, char **v)
{
  QApplication app(c,v);

  //qlist();
  qset();

  return app.exec();
}
