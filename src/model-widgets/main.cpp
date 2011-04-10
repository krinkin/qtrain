#include <QtGui>
#include "createModel.h"

int main( int argc, char **argv ) {
  QApplication app( argc, argv );
  QStandardItemModel *model 
    = createModel(&app);
  QSplitter hsplitter;
  QSplitter vsplitter(Qt::Vertical);

  QListView list;
  QTableView table;
  QTreeView tree;

  list.setModel( model );
  table.setModel( model );
  tree.setModel( model );	

  table.setColumnWidth(0, 200); 
  table.setColumnWidth(1, 150);
  tree.header()->resizeSection(0, 200);
  tree.header()->resizeSection(1, 150); 
  list.setSelectionModel( tree.selectionModel() );
  table.setSelectionModel( tree.selectionModel() );  
  table.setSelectionBehavior( QAbstractItemView::SelectRows );
  table.setSelectionMode( QAbstractItemView::SingleSelection );

  hsplitter.addWidget( &list );
  hsplitter.addWidget( &table );
  vsplitter.addWidget( &hsplitter );
  vsplitter.addWidget( &tree );
  vsplitter.setGeometry(300, 300, 500, 500);
  vsplitter.show();

  return app.exec();
}
