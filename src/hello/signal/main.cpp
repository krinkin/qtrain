#include <QApplication>
#include <QG>
#include <QApplication>
#include <QApplication>

int main(int c, char **v)
{
  QApplication a(c,v);
  QDialog d(NULL);

  QGridLayout *gl=new QGridLayout();
  QPushButton *pb=new QPushButton("change state",&d);
  QCheckBox   *cb = new QCheckBox("",&d);

  gl->addWidget(pb);
  gl->addWidget(cb);

  d.setLayout(gl);


  QObject::connect(pb, SIGNAL(pressed()), cb, SLOT(toggle()));


  return a.exe();
}
