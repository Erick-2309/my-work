#include "mywidget.h"


MyWidget::MyWidget(QWidget *parent) :QWidget(parent)
{
    this->setWindowTitle("fenètre sans paramètre");
    QTextEdit*m_te= new QTextEdit("text",this);
    QPushButton*m_pb=new QPushButton("quitter",this);
    //m_pb->setFont(QFont("Comic Sans MS", 14)); // Personnalisation du bouton
    //m_pb->setCursor(Qt::PointingHandCursor);

    QVBoxLayout*m_layout=new QVBoxLayout(this);
    m_layout->addWidget(m_te);
    m_layout->addWidget(m_pb);
    this->setLayout(m_layout);
}



MyWidget::MyWidget(const QString &text, const QString &button, QWidget*parent) :QWidget(parent)
{
    this->setWindowTitle("fenètre");
    m_te= new QTextEdit("votre text",this);
    m_te->setPlaceholderText(text);
    m_te->resize(300,300);
    m_te->move(100,100);

    m_pb=new QPushButton("quitter",this);
    m_pb->setText(button);
    m_pb->move(100,100);
    //m_pb->setFont(QFont("Comic Sans MS", 14));
    //m_pb->setCursor(Qt::PointingHandCursor);

    m_layout=new QVBoxLayout(this);
    m_layout->addWidget(m_te);
    m_layout->addWidget(m_pb);
    this->setLayout(m_layout);

    QMessageBox::information(this," Acceuil ","welcome");

    int retour =QMessageBox::question(this,"question","voulez vous continuer",QMessageBox::Yes|QMessageBox::No);
    if(retour==QMessageBox::Yes)
    {
        m_te->setText("you have shoosen yes");
    }
    else if(retour==QMessageBox::No)
    {
        m_te->setText("you have shoosen No ");
    }

    //QObject::connect(m_pb, &QPushButton::clicked, this, &MyWidget::confirm);
    QObject::connect(m_pb,SIGNAL(clicked()),this,SLOT(confirm())); //ancienne methode

    /*
      La syntaxe de connect() en Qt est la suivante :

      QObject::connect(sender, signal, receiver, slot);

      sender : l'objet qui émet le signal.
      signal : le signal émis par sender.
      receiver : l'objet qui recevra le signal et exécutera le slot.
      slot : la méthode (slot) appelée sur le récepteur lorsqu'il reçoit le signal.
    */


}

void MyWidget::confirm()
{
    QMessageBox::information(this,"","confirmation de fermeture");
    int retour_confirmation=QMessageBox::question(this,"question","vouler vous vraiment fermer cette page ? ",QMessageBox::Yes|QMessageBox::No);
    if(retour_confirmation==QMessageBox::Yes)
    {
        this->close();   //setText("you have shoosen yes");
    }

    else if(retour_confirmation==QMessageBox::No)
    {
        m_te->setText("you have shoosen to stay ");
    }

}

MyWidget::~MyWidget()
{

}
