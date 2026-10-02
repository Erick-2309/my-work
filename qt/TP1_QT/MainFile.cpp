#include "myfirstwidget.h"

int main(int argc, char *argv[])
 {
    QApplication app(argc, argv);

     /*QPushButton Hello("Hello World");
     Hello.setFont(QFont("Times New Roman",30,QFont::DemiBold));
     Hello.resize(60,60);
     Hello.setText("Bonjour");
     QTextEdit text("entrer votre text");

     text.show();
     Hello.show();


     //widget principal
     QWidget*window=new QWidget;
     window->setWindowTitle("window");

     QPushButton*button=new QPushButton("button", window);
     QTextEdit*text=new QTextEdit("entrer votretext", window);

     QLayout*layout=new QVBoxLayout(window);
     layout->addWidget(text);
     layout->addWidget(button);
     window->setLayout(layout);
     window->show();  */


    MyFirstWidget*m_MyFirstWidgets=new MyFirstWidget("valider","votre message");
    m_MyFirstWidgets->showWindow();

    MyFirstWidget*m_MyFirstWidget=new MyFirstWidget();
    m_MyFirstWidget->showWindow();

/*
    MyFirstWidget A("MY-button","M-text");
    MyFirstWidget B;
    A.showWindow();
    B.showWindow();*/



    //MyFirstWidget widget1("button","votre text",hLayout,mainWindow),widget2;
    //widget2.showWindow();
    //widget1.showWindow();

    return app.exec();
 }
