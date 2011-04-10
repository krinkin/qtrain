#ifndef LISTMODEL_H
#define LISTMODEL_H

#include <QAbstractListModel>

class ListModel : public QAbstractListModel
{
    Q_OBJECT;

public:
    ListModel(QObject* parent);
		virtual ~ListModel() {}

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
		void addRow();
		void removeRow();

 private:
		int m_rows;
};

#endif // LISTMODEL_H
