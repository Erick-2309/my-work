#include "calculatrice.h"


calculatrice::calculatrice(const QString & operateur, const QString &egalité, QWidget *parent):QWidget(parent)
{
    this->setWindowTitle("calculatrice par defaut ");



    m_pb1=new QPushButton("+",this);
    m_pb1->setText(operateur);
    m_pb2=new QPushButton("=",this);
    m_pb2->setText(egalité);


    m_le1=new QLineEdit("x",this);
    m_le1->setAlignment(Qt::AlignCenter);
    m_le2=new QLineEdit("Y",this);
    m_le2->setAlignment(Qt::AlignCenter);
    m_le3=new QLineEdit("Z",this);
    m_le3->setAlignment(Qt::AlignCenter);



    m_layout=new QHBoxLayout(this);
    m_layout->addWidget(m_le1);
    m_layout->addWidget(m_pb1);
    m_layout->addWidget(m_le2);
    m_layout->addWidget(m_pb2);
    m_layout->addWidget(m_le3);

    this->setLayout(m_layout);

}


    calculatrice::calculatrice()
{
    this->setWindowTitle("calculatrice");

    m_combo=new QComboBox();
    m_combo->addItem("+");
    m_combo->addItem("-");
    m_combo->addItem("*");
    m_combo->addItem("/");
    //m_combo->setStyleSheet("background-color: black; color: white;");


    m_pb2=new QPushButton("=");
    m_pb2->setStyleSheet("background-color: black; color: white;");


    m_le1=new QLineEdit();
    m_le1->setAlignment(Qt::AlignCenter);
    m_le2=new QLineEdit();
    m_le2->setAlignment(Qt::AlignCenter);
    m_le3=new QLineEdit();
    m_le3->setAlignment(Qt::AlignCenter);


    //m_pb1=new QPushButton(this);

    m_layout=new QHBoxLayout(this);
    m_layout->addWidget(m_le1);
    m_layout->addWidget(m_combo);
    m_layout->addWidget(m_le2);
    m_layout->addWidget(m_pb2);
    m_layout->addWidget(m_le3);

    this->setLayout(m_layout);
    //QObject::connect(m_pb2, SIGNAL(clicked()), this, SLOT(calcul()));
    QObject::connect(m_pb2,&QPushButton::clicked,this,&calculatrice::calcul);

}

void calculatrice::calcul()
{
    double result;
    if(m_combo->currentIndex()==0)
    {
        result = m_le1->text().toDouble() + m_le2->text().toDouble();
    }
    if(m_combo->currentIndex()==1)
    {
        result = m_le1->text().toDouble() - m_le2->text().toDouble();
    }
    if(m_combo->currentIndex()==2)
    {
        result = m_le1->text().toDouble() * m_le2->text().toDouble();
    }
    if(m_combo->currentIndex()==3)
    {
        result = m_le1->text().toDouble() / m_le2->text().toDouble();
    }
    m_le3->setText(QString::number(result));
}
