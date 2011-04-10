#ifndef CHATDIALOG_H
#define CHATDIALOG_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>
#include <QUdpSocket>

class ChatDialog : public QWidget
{
  Q_OBJECT;

  QLineEdit    *m_remotePort;
  QLineEdit    *m_message;
  QListWidget  *m_msgList;
  QPushButton  *m_sendButton;
  QUdpSocket   *m_socket;
  int           m_port;

public:
  ChatDialog(QWidget *parent, int port);

protected:
  void createServer();

public slots:
    void sendMessage();
    void readData();
};

#endif // CHATDIALOG_H
