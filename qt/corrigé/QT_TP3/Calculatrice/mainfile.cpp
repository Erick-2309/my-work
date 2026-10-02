#include "CCalculator.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    CCalculator *m_Calculator=new CCalculator();
    m_Calculator->show();  //  constructeur avec paramètres

    return a.exec();
}
