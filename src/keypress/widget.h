#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QKeyEvent>

class Widget : public QWidget
{
  Q_OBJECT

  QLabel *m_label;
public:
  explicit Widget(QWidget *parent = 0);

  void keyPressEvent(QKeyEvent *);

signals:

public slots:

};

#endif // WIDGET_H
