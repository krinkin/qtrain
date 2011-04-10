#include <QApplication>
#include "summatorform.h"

int main(int c, char **v)
{
    QApplication app(c,v);
    SummatorForm f(3,5,NULL);

    f.show();
    return app.exec();
}
