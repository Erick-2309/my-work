#include "ccalculator.h"

CCalculator::CCalculator()
{
    //m_poperator=new QLabel("+");

    m_pcombo=new QComboBox();
    m_pcombo->addItem("+");
    m_pcombo->addItem("-");
    m_pcombo->addItem("/");
    m_pcombo->addItem("*");

    m_pegal=new QPushButton("=");

    m_pope1=new QLineEdit();
    m_pope1->setAlignment(Qt::AlignCenter);

    m_pope2=new QLineEdit();
    m_pope2->setAlignment(Qt::AlignCenter);

    m_presult=new QLineEdit();
    m_presult->setAlignment(Qt::AlignCenter);

    //  Ajout d'un layout horizontalement
    QHBoxLayout *layout=new QHBoxLayout;
    layout->addWidget(m_pope1);
    layout->addWidget(m_pcombo);
    layout->addWidget(m_pope2);
    layout->addWidget(m_pegal);
    layout->addWidget(m_presult);
    this->setLayout(layout);
    QObject::connect(m_pegal,SIGNAL(clicked()),this,SLOT(Operation()));

}

void CCalculator::Operation(){
    double resultat;
    //  +
    if (m_pcombo->currentIndex()==0){
        resultat=m_pope1->text().toDouble()+m_pope2->text().toDouble();
    }
    //  -
    if (m_pcombo->currentIndex()==1){
        resultat=m_pope1->text().toDouble()-m_pope2->text().toDouble();
    }
    //  /
    if (m_pcombo->currentIndex()==2){
        resultat=m_pope1->text().toDouble()/m_pope2->text().toDouble();
    }
    //  *
    if (m_pcombo->currentIndex()==3){
        resultat=m_pope1->text().toDouble()*m_pope2->text().toDouble();
    }
    m_presult->setText(QString::number(resultat));
}
