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
#include <QPainter>
#include <QPushButton>
#include <QDebug>
#include <QApplication>
#include <QSpinBox>
#include <QVBoxLayout>

namespace Samples
{

	class Cell : public QWidget
	{
		public:
			Cell(QWidget *parent) : QWidget(parent)
			{
				setLayout(new QVBoxLayout(this));
				layout()->addWidget(new QPushButton("afgslkdfjglskd",this));
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

    QWidget *createEditor(QWidget *parent,
    const QStyleOptionViewItem &/* option */,
    const QModelIndex &/* index */) const
    {
       //return new  QLineEdit(parent);
			 return new  Cell(parent);
    }
    void paint(QPainter *painter, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const
    {


			if(index.row()!=2)
			{
				QItemDelegate::paint(painter,option,index);
				return;
			}

			qDebug() << "paint";

			QStyleOption cell;
			Cell *c=new Cell(this);

			cell.initFrom(c);	
			cell.rect=option.rect;
//			cell.state=QStyle::State_Enabled;
//			cell.text = "testkkkkkkk";

//			Cell *cell = new Cell(NULL);
//			o.initFrom(cell);

			qApp->style()->drawPrimitive(QStyle::PE_Widget,&cell,painter,c);
    //  qApp->style()->drawControl(QStyle::CE_PushButton,&cell,painter,new QSpinBox() );
		}
    
  private:    
    CustomItemDelegate(const CustomItemDelegate& obj);
    CustomItemDelegate& operator=(const CustomItemDelegate& obj);

  }; // class CustomItemDelegate
  
} // namespace Samples

#endif //_CustomItemDelegate_H_E27BB7A7_90AD_4BEC_92ED_A52828554127_INCLUDED_

/* ===[ End of file $HeadURL$ ]=== */
