#include <QtGui> 

QStandardItemModel* createModel(QObject* parent) {
    QStandardItemModel* model = new QStandardItemModel(5, 2, parent); 
    for( int r=0; r<5; r++ ) 
        for( int c=0; c<2; c++)  {
            QStandardItem *item = new QStandardItem(
                QString("Row:%0, Column:%1").arg(r).arg(c) ); 
            if( c == 0 ) 
                for( int i=0; i<3; i++ ) {                    
                    QStandardItem *child = new QStandardItem(
						QString("Item %0").arg(i) );
                    item->appendRow( child );
                }
            model->setItem(r, c, item);
        }
    model->setHorizontalHeaderItem( 0, new QStandardItem( "Name" ));
    model->setHorizontalHeaderItem( 1, new QStandardItem( "Value" ) );
    return model;
}
