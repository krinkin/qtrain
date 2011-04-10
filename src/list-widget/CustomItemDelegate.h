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
#include <QHBoxLayout>
#include <QPixmap>
#include <QPainter>
#include <QDebug>
#include <QPushButton>
#include <QLabel>

namespace Samples
{
  class MyWidget : public QWidget
  {
    Q_OBJECT;
  public:

    static const QSize getItemSize()
    {
      return QSize(300,50);
    }  
    
    MyWidget(QWidget* parent) : QWidget(parent)
    {
      setLayout(new QHBoxLayout(this));
      layout()->addWidget(new QPushButton("test",this));
      layout()->addWidget(new QLabel("some label",this));
      layout()->addWidget(new QPushButton("go!",this));
      setFixedSize(getItemSize());
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

    }

    virtual ~CustomItemDelegate()
    {
    }

   void paint ( QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index ) const
   {
      MyWidget *fakeItem = new MyWidget(NULL);

      QPixmap pm=QPixmap::grabWidget(fakeItem );
      painter->drawImage(option.rect, pm.toImage());
      qDebug() << option.rect;
   }

   QSize sizeHint ( const QStyleOptionViewItem & option, const QModelIndex & index ) const
   {
     return MyWidget::getItemSize();
   }

  private:    
    CustomItemDelegate(const CustomItemDelegate& obj);
    CustomItemDelegate& operator=(const CustomItemDelegate& obj);

  }; // class CustomItemDelegate
  
} // namespace Samples

#endif //_CustomItemDelegate_H_E27BB7A7_90AD_4BEC_92ED_A52828554127_INCLUDED_

/* ===[ End of file $HeadURL$ ]=== */
