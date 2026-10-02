#include "mywidget.h"

MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
    QTextEdit *m_tE = new QTextEdit("TextEdit", this);
    QPushButton *m_pB = new QPushButton("Quitter", this);
}

MyWidget::MyWidget(char *TextBouton, char *textTextEdit, QWidget *parent) : QWidget(parent)
{
    /*QTextEdit *m_tE=new QTextEdit("test",this);
    m_tE->setText(TextBouton);
    //m_tE->move(100,100);    //  Permet de fixer la position en absolu*/

    /*QPushButton *m_pB=new QPushButton("tests",this);
    m_pB->setText(textTextEdit);
   // m_pB->move(10,100); //  Permet de fixer la position en absolu
    m_pB->setCursor(Qt::WaitCursor);    //  Permet de changer le curseur de la souris quand on est sur l'objet
    */

    //  Ajout d'un layout horizontalement
    /*QHBoxLayout *layout=new QHBoxLayout;
    layout->addWidget(m_tE);
    layout->addWidget(m_pB);
    this->setLayout(layout);*/

    //  Ajout d'un layout horizontalement
    /*QVBoxLayout *layout=new QVBoxLayout;
    layout->addWidget(m_tE);
    layout->addWidget(m_pB);
    this->setLayout(layout);*/

    //  Ajout d'un layout horizontalement
    /*QGridLayout *layout=new QGridLayout;
    layout->addWidget(m_tE,0,0);
    layout->addWidget(m_pB,1,1);
    this->setLayout(layout);*/
    /*
        QLineEdit *nameEdit = new QLineEdit(this);
        QLineEdit *addrEdit = new QLineEdit(this);
        QLineEdit *occpEdit = new QLineEdit(this);
        QLineEdit *passWrd = new QLineEdit(this);
        QFormLayout *formLayout = new QFormLayout;
        formLayout->setLabelAlignment(Qt::AlignRight | Qt::AlignVCenter);
        formLayout->addRow("Name:", nameEdit);
        formLayout->addRow("Email:", addrEdit);
        formLayout->addRow("Age:", occpEdit);
        passWrd->setEchoMode(QLineEdit::Password);
        formLayout->addRow("Passwrd:", passWrd);

        setLayout(formLayout);
    */

    // QMessageBox::question(this, "", "");

    QTextEdit *m_tE = new QTextEdit("test", this);
    m_tE->setText(TextBouton);
    QPushButton *m_pB = new QPushButton("QUITTER", this);
    m_pB->move(10, 100);
    m_pB->setText(textTextEdit);

    QMessageBox::standardButton retour;
    int retour = QMessageBox::question(this, "Titre", "choisir yes ou no", QMessageBox::Yes | QMessageBox::No);
    if (retour == QMessageBox::Yes)
    {
        m_tE->setText("yes");
    }
    else if (retour == QMessageBox::No)
    {
        m_tE->setText("no");
    }

    QObject::connect(m_pB, SIGNAL(clicked()), qApp, SLOT(quit()));

    //  Ajout d'un layout horizontalement
    /* QVBoxLayout *layout=new QVBoxLayout;
     layout->addWidget(m_tE);
     layout->addWidget(m_pB);
     this->setLayout(layout);
     //  Remarque : qApp est un pointeur vers l'objet de type QApplication
     //  créé dans le main (cela est réalisé automatiquement)
     QObject::connect(m_pB,SIGNAL(clicked()),qApp,SLOT(quit()));
 */
    /*
    QMessageBox::information(this, "Titre", "Test");
    //  Affiche directement une boîte de dialogue
    int retour=QMessageBox::question(this,"Titre","choisir yes ou no",QMessageBox::Yes|QMessageBox::No);
    if(retour==QMessageBox::Yes){
        m_tE->setText("yes");
    }
    else if(retour==QMessageBox::No){
        m_tE->setText("no");
    }
    */
    /*
        QLCDNumber* lcd = new QLCDNumber( this );
        QSlider* slider = new QSlider( Qt::Horizontal, this );
        QVBoxLayout *mainLayout = new QVBoxLayout;
        mainLayout->addWidget(lcd);
        mainLayout->addWidget(slider);
        setLayout(mainLayout);
        connect( slider, SIGNAL(valueChanged(int)), lcd, SLOT(display(int)) );
    */
}
