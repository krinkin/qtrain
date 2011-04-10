#include <QApplication>
#include <QDialog>
#include <QVBoxLayout>
#include "ui_test.h"


int main(int c, char **v)
{
  QApplication a(c,v);

  QDialog *d = new QDialog;

  Ui::Test ui;

  ui.setupUi(d);

  d->show();

  return a.exec();
}

