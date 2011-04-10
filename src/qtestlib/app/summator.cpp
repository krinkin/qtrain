#include "summator.h"

Summator::Summator(int x, int y, QObject * parent)
{
    m_x = x;
    m_y = y;
    setParent(parent);
}

int Summator::sum()
{
    return m_x + m_y;
}

int Summator::setX(int x)
{
    int oldValue = m_x;
    m_x = x;
    emit valueChanged();
    return oldValue;
}

int Summator::setY(int y)
{
    int oldValue = m_y;
    m_y = y;
    emit valueChanged();
    return oldValue;
}
