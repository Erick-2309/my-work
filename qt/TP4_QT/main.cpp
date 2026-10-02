
#include "interfaces.h"

int main(int argc,char*argv[])
{
    QApplication app (argc,argv);

    interfaces A("formulaire","quitter"),B;
    A.show();

    //B.show();

    return app.exec();
}
