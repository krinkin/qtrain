#ifndef TASK_H
#define TASK_H

#include <QRunnable>

class Task : public QRunnable
{
public:
    explicit Task();

  void run();


};

#endif // TASK_H
