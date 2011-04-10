#ifndef SUMMATOR_H
#define SUMMATOR_H

#include <QObject>

class Summator : public QObject
{
    Q_OBJECT;
    int m_x;
    int m_y;

public:
    Summator(int x, int y, QObject * parent);
    int setX(int x);
    int setY(int y);

    int sum();

signals:
    void valueChanged();

};

#endif // SUMMATOR_H
