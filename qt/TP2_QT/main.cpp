#include "mywidget.h"

int main(int argc, char*argv[])
{
    QApplication app(argc,argv);

    MyWidget A("votre text","quitter"),B;
    A.show();
    //B.show();

    return app.exec();
}
