#include "texter.h"
#include <QVBoxLayout>
#include <QDebug>
#include <QMessageAccountId>
#include <QMessageManager>

Texter::Texter(QWidget *parent) :
    QDialog(parent)
{
  setLayout(new QVBoxLayout());

  m_number = new QLineEdit("+7921???????",this);
  m_text = new QLineEdit("hello",this);
  m_send = new QPushButton("send",this);
  m_MessageService = new QMessageService(this);

  layout()->addWidget(m_number);
  layout()->addWidget(m_text);
  layout()->addWidget(m_send);


  connect(m_send, SIGNAL(clicked()), this, SLOT(sendEvent()));
  connect(m_MessageService, SIGNAL(stateChanged(QMessageService::State)), this, SLOT(completeEvent()));
}

void Texter::sendEvent()
{
  QMessageManager mgr(this);

  QMessage msg;

  msg.setType(QMessage::Sms);
  msg.setBody(m_text->text());
  QMessageAddress address(QMessageAddress::Phone,m_number->text());
  msg.setTo(address);

  msg.setParentAccountId(mgr.queryAccounts()[0]);

  QMessageService svc(this);
  m_sendId = msg.id();

  qDebug() << "id = " << msg.id().toString();

  qDebug() << "send result" << svc.send(msg);
}

void Texter::completeEvent()
{
  qDebug() << "state=" << m_MessageService->state();
}
