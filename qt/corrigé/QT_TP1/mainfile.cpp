#include "myfirstclass.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //  To show each widget with its own interface
    /*QTextEdit *m_tE=new QTextEdit("test");
    //QPushButton *m_pB=new QPushButton("tests");
    //m_pB->show();
    m_tE->show();*/

    //  To show the widgets into one interface
    /*QWidget *w=new QWidget();
    QTextEdit *m_tE=new QTextEdit("test",w);
    QPushButton *m_pB=new QPushButton("tests",w);
    w->show();*/

    // My First Class
    //MyFirstClass *m_fClass=new MyFirstClass();
    //m_fClass->show(); //  constructeur sans paramètre

    MyFirstClass *m_fClassParam=new MyFirstClass("toto","tata");
    m_fClassParam->show();  //  constructeur avec paramètres

    return a.exec();
}
