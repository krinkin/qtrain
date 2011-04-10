#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QAction>
#include <QToolBar>

class MainWindow : public QMainWindow
{
  QMenu    *m_fileMenu;
  QMenu    *m_fileSubMenu;
  QAction  *m_openAction;
  QAction  *m_closeAction;
  QAction  *m_showAction;
  QToolBar *m_fileToolbar;
  QToolBar *m_filesubToolbar;


public:

    MainWindow();

public slots:
    void showToolbars();
    void newDocument();

protected:
    void createActions();
    void createMenu();
    void createToolbars();

};

#endif // MAINWINDOW_H
