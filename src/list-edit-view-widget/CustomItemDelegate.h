/* $Id$ */
/*!
 * \file CustomItemDelegate.h
 * \brief Header of CustomItemDelegate
 * \todo add comment here
 *
 * File description
 *
 * PROJ: OSLL/qtrain
 * ---------------------------------------------------------------- */


#ifndef _CustomItemDelegate_H_E27BB7A7_90AD_4BEC_92ED_A52828554127_INCLUDED_
#define _CustomItemDelegate_H_E27BB7A7_90AD_4BEC_92ED_A52828554127_INCLUDED_

#include <QItemDelegate>
#include <QLineEdit>
#include <QItemEditorFactory>
#include <QPushButton>
#include <QSpinBox>
#include <QPainter>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QFont>



#include <QDebug>

namespace Samples
{
    static const QSize ItemSize=QSize(200,50);

    class QMyWidget : public QWidget
    {
        Q_OBJECT;

        QModelIndex  m_idx;
        QLineEdit   *m_le;
        QPushButton *m_pb;

    public:
        QMyWidget(QWidget *parent,const QModelIndex &index) : QWidget(parent)
        {
            m_idx = index;
            QString value=m_idx.model()->data(m_idx,Qt::DisplayRole).toString();


            m_le = new QLineEdit(value,parent);

            setLayout(new QHBoxLayout());
            layout()->addWidget(m_le);
            layout()->addWidget(m_pb);

        }
        QSize sizeHint(const QStyleOptionViewItem &option,  const QModelIndex &index ) const
        {
            return ItemSize;
        }

        QString getValue() const
        {
            return m_le->text();
        }

    };

 /*!
   * Class description. May use HTML formatting
   *
   */
  class CustomItemDelegate : public QItemDelegate
  {
     Q_OBJECT;
  public:
    CustomItemDelegate(QWidget *parent =NULL) : QItemDelegate(parent)
    {
       // m_widget = new QMyWidget(parent);
    }

    virtual ~CustomItemDelegate()
    {
    }

    QSize sizeHint(const QStyleOptionViewItem &option,  const QModelIndex &index ) const
    {
        return ItemSize;
    }

    void setModelData(QWidget *editor, QAbstractItemModel *model,  const QModelIndex &index) const
     {
        QString value = qobject_cast<QMyWidget*>(editor)->getValue();
        model->setData(index, value, Qt::EditRole);
     }

    void paint(QPainter *painter, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const
    {

        static QWidget *w = new QPushButton("OOO!!!",NULL);
        w->resize(100,20);

//        painter->end();
        w->render(painter->device(),QPoint(),option.rect);
      
        #if 0

        QFont font("Helvetica",15,5,true);
        painter->setFont(font);
        painter->setPen(Qt::red);

        painter->drawText(option.rect,index.model()->data(index,Qt::DisplayRole).toString());

        painter->setPen(Qt::blue);
        painter->drawRect(option.rect);
        #endif
    }

    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &/* option */,  const QModelIndex &index) const
    {
       return new QMyWidget(parent,index);
    }
  private:    
    CustomItemDelegate(const CustomItemDelegate& obj);
    CustomItemDelegate& operator=(const CustomItemDelegate& obj);

    QMyWidget *m_widget;

  }; // class CustomItemDelegate
  
} // namespace Samples

#endif //_CustomItemDelegate_H_E27BB7A7_90AD_4BEC_92ED_A52828554127_INCLUDED_

/* ===[ End of file $HeadURL$ ]=== */
