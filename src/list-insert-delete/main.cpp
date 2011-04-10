/* $Id: main.cpp 5 2009-11-27 15:30:12Z kkv $ */


#include <QApplication>
#include <QHBoxLayout>
#include <QDialog>
#include <QPushButton>
#include "listmodel.h"
#include "ListView.h"

int main(int c, char **v)
{
	QApplication 	app(c,v);
	
	QDialog dialog(NULL);

	Samples::ListView *listView  = new Samples::ListView(&dialog);


	QPushButton *addBtn = new QPushButton("add    row", &dialog);
	QPushButton *remBtn = new QPushButton("remove row", &dialog);

	dialog.setLayout(new QHBoxLayout());
  dialog.layout()->addWidget(listView);
	dialog.layout()->addWidget(addBtn);
	dialog.layout()->addWidget(remBtn);


	dialog.connect(addBtn,SIGNAL(pressed()),listView,SLOT(addRow()));
	dialog.connect(remBtn,SIGNAL(pressed()),listView,SLOT(removeRow()));

	dialog.show();

	return app.exec();

}

