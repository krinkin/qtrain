#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>


class Widget : public QWidget
{
  Q_OBJECT

  QLabel      *m_label;
  QLabel      *m_labelp;
  QPushButton *m_button;

public:
  explicit Widget(QWidget *parent = 0);

signals:

public slots:

  void changeLang();

};

#endif // WIDGET_H
