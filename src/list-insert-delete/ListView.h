/* $Id$ */
/*!
 * \file ListView.h
 * \brief Header of ListView
 * \todo add comment here
 *
 * File description
 *
 * PROJ: OSLL/qtrain
 * ---------------------------------------------------------------- */


#ifndef _ListView_H_75641781_70ED_4F35_9CC3_E218797BF118_INCLUDED_
#define _ListView_H_75641781_70ED_4F35_9CC3_E218797BF118_INCLUDED_

#include <QListView>
#include <QDebug>
#include "listmodel.h"

namespace Samples
{
 /*!
   * Class description. May use HTML formatting
   *
   */
  class ListView : public QListView
  {
		Q_OBJECT;

  public:
    ListView(QWidget *parent) : QListView(parent) 
    {
			m_model = new ListModel(this);
			setModel(m_model); 
    }

    virtual ~ListView() 
    {
    }

	public slots:
		void addRow()
		{
			qDebug() << "addrow";
			m_model->addRow();
		}

		void removeRow()
		{
			qDebug() << "rem";
			m_model->removeRow();
		}

  private:    
    ListView(const ListView& obj);
    ListView& operator=(const ListView& obj);
		ListModel *m_model;


  }; // class ListView
  
} // namespace Samples

#endif //_ListView_H_75641781_70ED_4F35_9CC3_E218797BF118_INCLUDED_

/* ===[ End of file $HeadURL$ ]=== */
