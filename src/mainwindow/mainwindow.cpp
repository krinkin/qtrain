#include "mainwindow.h"
#include <QMenuBar>
#include <QAction>
#include <QTextDocument>

MainWindow::MainWindow() : QMainWindow(NULL)
{
  createActions();
  createMenu();
  createToolbars();

  setDocumentMode(true);

  connect( m_showAction, SIGNAL(triggered()), this, SLOT(showToolbars()));
  connect( m_openAction, SIGNAL(triggered()), this, SLOT(newDocument()));

  setCentralWidget(new QWidget(this));
}

void MainWindow::createActions()
{
  m_openAction = new QAction(tr("&New"),this);
  m_closeAction = new QAction(tr("&Close"),this);
  m_showAction = new QAction(tr("&Show"),this);
}

void MainWindow::newDocument()
{
  MainWindow *newmw = new MainWindow;

  newmw->show();
}


void MainWindow::createMenu()
{
  m_fileMenu = new QMenu(tr("&File"));
  m_fileMenu->addAction(m_openAction);
  m_fileMenu->addAction(m_closeAction);


  m_fileSubMenu = new QMenu(tr("&Submenu"),this);
  m_fileSubMenu->addAction(m_openAction);
  m_fileSubMenu->addAction(m_closeAction);
  m_fileSubMenu->addAction(m_showAction);

  m_fileMenu->addMenu( m_fileSubMenu);

  menuBar()->addMenu(m_fileMenu);
}

void MainWindow::createToolbars()
{
  m_filesubToolbar = addToolBar(tr("&File"));
  m_fileToolbar = addToolBar(tr("&SubToolBar"));

  m_fileToolbar->addAction(m_openAction);
  m_filesubToolbar->addAction(m_closeAction);
  m_filesubToolbar->addAction(m_openAction);

}


void MainWindow::showToolbars()
{
  m_filesubToolbar->show();
  m_fileToolbar->show();
}
