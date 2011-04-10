#include "listmodel.h"
#include <QDebug>

ListModel::ListModel(QObject *parent) : QAbstractListModel(parent)
{
	m_rows = 10;
}

int ListModel::rowCount(const QModelIndex &parent) const
{
	Q_UNUSED(parent);
	return m_rows;	
}

QVariant ListModel::data(const QModelIndex &index, int role) const
{
	if ( Qt::DisplayRole == role )
	{
		QString value = "data: index=" + QString::number(index.row());
		return value;
	}
	return QVariant();
}

void ListModel::addRow()
{
	m_rows++;
	layoutChanged();
}

void ListModel::removeRow()
{
	if(m_rows > 0 )
		m_rows--;
	layoutChanged();
}
