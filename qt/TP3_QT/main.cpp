
#include "calculatrice.h"
#include <QtWidgets/qapplication.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    calculatrice C,D("+","=");
    D.show();
    C.show();
    return a.exec();
}
