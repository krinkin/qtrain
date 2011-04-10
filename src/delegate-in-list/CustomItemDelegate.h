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

namespace Samples
{
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
       return new  QLineEdit(parent);
    }
    
  private:    
    CustomItemDelegate(const CustomItemDelegate& obj);
    CustomItemDelegate& operator=(const CustomItemDelegate& obj);

  }; // class CustomItemDelegate
  
} // namespace Samples

#endif //_CustomItemDelegate_H_E27BB7A7_90AD_4BEC_92ED_A52828554127_INCLUDED_

/* ===[ End of file $HeadURL$ ]=== */
