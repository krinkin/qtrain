#ifndef TEXTER_H
#define TEXTER_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>
#include <QMessage>
#include <QMessageAddress>
#include <QMessageService>

using namespace QtMobility;

class Texter : public QDialog
{
    Q_OBJECT

    QLineEdit *m_number;
    QLineEdit *m_text;
    QPushButton *m_send;
    QMessageService *m_MessageService;
    QMessageId m_sendId;

public:
    explicit Texter(QWidget *parent = 0);

signals:

public slots:

    void sendEvent();
    void completeEvent();

};

#endif // TEXTER_H
