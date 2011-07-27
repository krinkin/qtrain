#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QKeyEvent>
#include <QSet>

class Widget : public QWidget
{
  Q_OBJECT

  QLabel *m_label;
  QSet<char> m_keys;

public:
  explicit Widget(QWidget *parent = 0);

  void keyPressEvent(QKeyEvent *);
  void keyReleaseEvent(QKeyEvent *);

signals:
  void keysChanged();

public slots:
  void updateLabel();

};

#endif // WIDGET_H
