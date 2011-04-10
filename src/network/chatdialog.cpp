#include "chatdialog.h"
#include <QVBoxLayout>
#include <QHBoxLayout>

ChatDialog::ChatDialog(QWidget *parent, int port) : QWidget(parent), m_port(port)
{
  QVBoxLayout *l = new QVBoxLayout;
  m_remotePort =new QLineEdit(this);
  m_msgList = new QListWidget(this);
  m_sendButton = new QPushButton("send",this);
  m_message = new QLineEdit(this);

  QHBoxLayout *hl = new QHBoxLayout;
  hl->addWidget(m_remotePort);
  hl->addWidget(m_message);


  l->addWidget(m_msgList);
  l->addItem(hl);
  l->addWidget(m_sendButton);

  m_message->setText("Hello world");
  m_remotePort->setText("10021");

  setWindowTitle(QString("Local port:")+QString::number(m_port));

  setLayout(l);

  createServer();

  connect(m_sendButton, SIGNAL(clicked()), this, SLOT(sendMessage()));
  connect(m_socket, SIGNAL(readyRead()), this, SLOT(readData()));
}

void ChatDialog::sendMessage()
{
  QByteArray data=m_message->text().toAscii();
  m_socket->writeDatagram(data,QHostAddress::LocalHost,m_remotePort->text().toInt());
  qDebug() << "Sent\n";
}

void ChatDialog::createServer()
{
  m_socket = new QUdpSocket(this);
  m_socket->bind(QHostAddress::LocalHost, m_port);

  qDebug() << "port = " << m_port;
}

void ChatDialog::readData()
{
  qDebug() << "Read\n";
   while (m_socket->hasPendingDatagrams())
   {
     QByteArray datagram;
     datagram.resize(m_socket->pendingDatagramSize());
     QHostAddress sender;
     quint16 senderPort;
     m_socket->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);

     QString data(datagram);
     m_msgList->insertItem(0,data);

   }
}
