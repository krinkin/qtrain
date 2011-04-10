#ifndef CENTRALWIDGET_H
#define CENTRALWIDGET_H

#include <QWidget>

class CentralWidget : public QWidget
{
public:
    CentralWidget(QWidget *parent);

    void paintEvent(QPaintEvent *pe)
    {

    }
};

#endif // CENTRALWIDGET_H
