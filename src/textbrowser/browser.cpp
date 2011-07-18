#include "browser.h"

Browser::Browser(QWidget *parent) :
    QTextBrowser(parent)
{
   setSource(QUrl("qrc:/html/index.html"));
}
