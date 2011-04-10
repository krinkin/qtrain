#include "dialog.h"
#include "CustomItemDelegate.h"
#include <QHBoxLayout>
#include <QStandardItemModel>
#include <QListWidgetItem>

Dialog::Dialog() : QDialog(NULL)
{
    setLayout(new QHBoxLayout(this));

    m_list = new QListView(this);
    QStandardItemModel *model=new QStandardItemModel(15,1,this);

    m_list->setModel(model);

    m_list->setItemDelegate(new Samples::CustomItemDelegate(this));
    m_list->setGridSize(Samples::ItemSize);

    layout()->addWidget(m_list);

}
