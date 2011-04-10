#include "dialog.h"
#include "CustomItemDelegate.h"
#include <QHBoxLayout>
#include <QStandardItemModel>

Dialog::Dialog() : QDialog(NULL)
{
    setLayout(new QHBoxLayout(this));
    m_list = new QListView(this);
    QStandardItemModel *model=new QStandardItemModel(15,1,this);

    model->setItem(3,new QStandardItem("text"));
    m_list->setModel(model);

    m_list->setItemDelegate(new Samples::CustomItemDelegate(this));

    m_list->setBaseSize(500,500);
    m_list->setFixedHeight(200);


    layout()->addWidget(m_list);

}
