#ifndef THREAD_H
#define THREAD_H

#include <QThread>

class Thread : public QThread
{
    Q_OBJECT
    QString m_name;

public:
    explicit Thread(const QString& name, QObject *parent = 0);

protected:
  void run();

signals:

public slots:

};

#endif // THREAD_H
