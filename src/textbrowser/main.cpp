#include <QApplication>
#include "browser.h"


int main(int c, char **v)
{
  QApplication app(c,v);

  Browser b;

  b.show();

  return app.exec();
}
