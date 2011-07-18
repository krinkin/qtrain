#include <QApplication>
#include "widget.h"
#include <QTranslator>

int main(int c, char **v)
{
  QApplication app(c,v);
//  QTranslator tr;
//  tr.load("sample_ru");
//  app.installTranslator(&tr);


  Widget w;
  w.show();

  return app.exec();
}
