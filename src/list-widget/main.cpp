/* $HeadURL: svn+ssh://kkv@osll.spb.ru/var/svnroot/qtrain/src/templates/dialog/main.cpp $ */
/* $Id: main.cpp 5 2009-11-27 15:30:12Z kkv $ */

#include <QApplication>

#include "dialog.h"

int main(int c, char **v)
{
	QApplication 	app(c,v);
	
        Dialog dialog;

	dialog.show();

	return app.exec();

}

