#ifndef FORM_H
#define FORM_H

#include <QtGui/QWidget>

namespace Ui {
    class Form;
}

class Form : public QWidget {
    Q_OBJECT
public:
    Form(QWidget *parent = 0);
    ~Form();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::Form *m_ui;
};

#endif // FORM_H
