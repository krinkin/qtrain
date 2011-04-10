#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QListView>

class Dialog : public QDialog
{
public:
    Dialog();

private:
    QListView *m_list;
};

#endif // DIALOG_H
