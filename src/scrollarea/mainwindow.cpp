#include "mainwindow.h"
#include <QLayout>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QScrollBar>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
  m_sa = new QScrollArea(this);

  setCentralWidget(m_sa);

  QTextEdit *te = new QTextEdit(this);
  te->setMinimumSize(QSize(1000,2000));
  te->setText("very long message\nvery long message\nvery long message\nvery long message\nvery long message\nvery long message\nvery long message\nvery long message\nvery long message\n");
  m_sa->setWidget(te);

}
