#ifndef SUMMATORFORM_H
#define SUMMATORFORM_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include "summator.h"

class SummatorForm : public QDialog
{
    Q_OBJECT

    friend class TestForm;

    Summator  *m_summator;
    QLabel    *m_sum;
    QLineEdit *m_x;
    QLineEdit *m_y;
    QPushButton *m_update;


public:
    explicit SummatorForm(int x, int y, QWidget *parent = 0);

signals:


public slots:

    void reloadValues();
    void updateSum();
};

#endif // SUMMATORFORM_H
