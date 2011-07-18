#include <QApplication>
#include "widget.h"

int main(int c, char **v)
{
  QApplication app(c,v);

  Widget w;
  w.show();

  return app.exec();
}
