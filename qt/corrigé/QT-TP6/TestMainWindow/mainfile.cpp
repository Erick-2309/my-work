#include "myclass.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MyClass *fenetre=new MyClass();
    fenetre->show();

    return app.exec();
}

