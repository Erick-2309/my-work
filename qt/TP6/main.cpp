#include "myclass.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MYCLASS *fenetre=new MYCLASS();
    fenetre->show();
    // void MYCLASS::AfficherImage();

    //#include "MyMdiArea.h"

    // Dans le constructeur de MainWindow :
    MyMdiArea *mdiArea = new MyMdiArea();
    //setCentralWidget(mdiArea);


    return app.exec();

}
