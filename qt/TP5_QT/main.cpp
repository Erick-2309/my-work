
#include<QApplication>
#include "timer.h"

int main(int argc, char *argv[])
{
     QApplication app(argc,argv);
    Timer T;
     T.show();

    return app.exec();
}


