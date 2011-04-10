#ifndef TEST_H
#define TEST_H

#include <QtGui/QWidget>

namespace Ui {
    class Test;
}

class Test : public QWidget {
    Q_OBJECT
public:
    Test(QWidget *parent = 0);
    ~Test();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Test *m_ui;
};

#endif // TEST_H
