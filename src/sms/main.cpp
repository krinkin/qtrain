#include <QApplication>
#include "texter.h"

int main(int c, char **v)
{
  QApplication app(c,v);

  Texter t(NULL);

  t.showMaximized();

  return app.exec();
}
