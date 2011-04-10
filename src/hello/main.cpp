#include <QApplication>
#include <QVBoxLayout>
#include <QDialog>
#include <QLabel>
#include <QPushButton>

int main(int c, char **v)
{
  QApplication a(c,v);
  QDialog d(NULL);

  d.setLayout(new QVBoxLayout());
  d.layout()->addWidget(new QLabel("Hello world!", &d));
  
  d.show();
  return a.exec();
}
