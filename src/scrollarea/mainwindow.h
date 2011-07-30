#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScrollArea>

class MainWindow : public QMainWindow
{
  Q_OBJECT

  QScrollArea   *m_sa;

public:
  explicit MainWindow(QWidget *parent = 0);

signals:

public slots:

};

#endif // MAINWINDOW_H
