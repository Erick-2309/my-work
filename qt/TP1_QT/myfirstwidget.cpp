#include "myfirstwidget.h"
#include <QtWidgets/qlineedit.h>


MyFirstWidget::MyFirstWidget(QWidget*parent):QWidget(parent)
{
    QTextEdit*m_text=new QTextEdit("text",this);
    QPushButton*m_button=new QPushButton("button",this);
    m_button->move(100,100);
    m_text->move(10,100);

    QVBoxLayout* m_layout = new QVBoxLayout(this);
    //QGridLayout*m_layout=new QGridLayout(this);
    m_layout->addWidget(m_text);
    m_layout->addWidget(m_button);

    this->setLayout(m_layout);
}

MyFirstWidget::MyFirstWidget(const QString&Textbutton,const QString&textTextEdit, QWidget*parent): QWidget(parent)
{
    this->setWindowTitle("window");
    //this->resize(500,500);

    QLineEdit*name=new QLineEdit(this);
    QLineEdit*firstname=new QLineEdit(this);
    QLineEdit*birthday=new QLineEdit(this);
    QLineEdit*formation=new QLineEdit(this);
    QLineEdit*password=new QLineEdit(this);
    QFormLayout*form = new QFormLayout(this);
    form->setLabelAlignment(Qt::AlignRight|Qt::AlignVCenter);

    form->addRow("name",name);
    form->addRow("firstname",firstname);
    form->addRow("birthday",birthday);
    form->addRow("formation",formation);
    password->setEchoMode(QLineEdit::Password);
    form->addRow("password",password);

    QTextEdit*m_text= new QTextEdit("votre text",this);//ou parent
    m_text->setText(textTextEdit);
    //m_text->move(200,200);
    m_text->resize(300,300);

    QPushButton*m_button=new QPushButton("votre button",this);//ou parebnt
    m_button->setText(Textbutton);
    m_button->move(300,300);
    m_button->resize(60,30);

    QVBoxLayout*m_layout=new QVBoxLayout(this);
    //QGridLayout*m_layout=new QGridLayout(this);
    m_layout->addWidget(m_text);      //ajout du textedit au layout
    m_layout->addWidget(m_button);    //ajout du button au layout




   QVBoxLayout*principal_layout=new QVBoxLayout(this);
   principal_layout->setAlignment(Qt::AlignVCenter);
   principal_layout->addLayout(form);
   principal_layout->addLayout(m_layout);
   this->setLayout(principal_layout);      //applicationde layout



}

void MyFirstWidget::showWindow()
{
    this->show(); //ou parent ->
}


MyFirstWidget::~MyFirstWidget()
{
}


