#include "widget.h"
#include <QVBoxLayout>
#include <QApplication>
#include <QTranslator>

Widget::Widget(QWidget *parent) :
    QWidget(parent)
{
  setLayout(new QVBoxLayout());
  m_label = new QLabel(tr("This is a label text"));
  m_labelp = new QLabel(tr("This is %1 label better than %2").arg(tr("new")).arg(tr("first")));
  m_button = new QPushButton(tr("Change language"),this);


  layout()->addWidget(m_label);
  layout()->addWidget(m_labelp);
  layout()->addWidget(m_button);
  connect(m_button, SIGNAL(clicked()), this, SLOT(changeLang()));

}

void Widget::changeLang()
{
  QTranslator *tr=new QTranslator();
  tr->load("sample_ru");


  qApp->installTranslator(tr);
  m_label->setText(QApplication::translate("Widget","This is a label text",NULL,QApplication::UnicodeUTF8));
}
