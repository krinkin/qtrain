#include "summatorform.h"
#include <QVBoxLayout>
#include <QDebug>

SummatorForm::SummatorForm(int x, int y, QWidget *parent) :
    QDialog(parent)
{
    m_summator = new Summator(x,y,this);
    m_sum = new QLabel(QString::number(m_summator->sum()),this);
    m_x = new QLineEdit(QString::number(x),this);
    m_y = new QLineEdit(QString::number(y),this);
    m_update = new QPushButton("update",this);

    setLayout(new QVBoxLayout());
    layout()->addWidget(m_sum);
    layout()->addWidget(m_x);
    layout()->addWidget(m_y);
    layout()->addWidget(m_update);

    connect(m_update,SIGNAL(clicked()), this, SLOT(reloadValues()));
    connect(m_summator, SIGNAL(valueChanged()), this, SLOT(updateSum()));
}

void SummatorForm::reloadValues()
{
    qDebug() << "reloadValues()";
    m_summator->setX(m_x->text().toInt());
    m_summator->setY(m_y->text().toInt());
}

void SummatorForm::updateSum()
{
    qDebug() << "updateSum()";
    m_sum->setText(QString::number(m_summator->sum()));
}
