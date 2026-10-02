#include "formulaire.h"
#include <QtWidgets/qlineedit.h>
//class interfaces;
Formulaire::Formulaire(QWidget *parent) :QDialog(parent)
{
    QWidget*formululaire=new QWidget();
    formululaire ->setWindowTitle("formulaire");

    nom=new QLabel("nom");
    prenoms=new QLabel("prenom");
    age =new QLabel("née le");
    formation=new QLabel("formation");

    valeur_nom=new QLineEdit();
    valeur_prenoms=new QLineEdit();
    valeur_age =new QDateEdit();
    valeur_formation=new QLineEdit();

    QFormLayout*Form = new QFormLayout();
    Form->setFormAlignment(Qt::AlignRight|Qt::AlignCenter);
    Form->addRow(nom,valeur_nom);
    Form->addRow(prenoms,valeur_prenoms);
    valeur_age->setCalendarPopup(true);
    Form->addRow(age ,valeur_age);
    Form->addRow(formation,valeur_formation);

    OK=new QPushButton(this);
    OK->setText("OK");

    cancel=new QPushButton(this);
    cancel->setText("cancel");

    QHBoxLayout*hLayout= new QHBoxLayout();
    hLayout->addWidget(OK);
    hLayout->addWidget(cancel);



    QVBoxLayout*Layout=new QVBoxLayout(this);
    Layout->addLayout(Form);
    Layout->addLayout(hLayout);

    this->setLayout(Layout);


    //QObject::connect(OK,SIGNAL(clicked()),this,SLOT(accept()));
    QObject::connect(OK,&QPushButton::clicked,this,&::Formulaire::accept);
    QObject::connect(cancel,&QPushButton::clicked,this,&::Formulaire::reject);

}


QString Formulaire::getNom()  { return valeur_nom->text(); }
QString Formulaire::getPrenoms()  { return valeur_prenoms->text(); }
QString Formulaire::getAge()  { return valeur_age->date().toString("dd/MM/yyyy"); }
QString Formulaire::getFormation()  { return valeur_formation->text(); }

/*
void Formulaire::quit()
{
    int retour = QMessageBox::question(this,"fermeture","vouler vous quitter cettepage ?",QMessageBox::Yes|QMessageBox::No);
    if(retour==QMessageBox::Yes)
    {
        this->close();
    }

}


void Formulaire::remplir()
{

    if(valeur_nom->text().isEmpty() || valeur_prenoms->text().isEmpty() || valeur_age->text().isEmpty() || valeur_formation->text().isEmpty())
    {
        QMessageBox::warning(this,"champ obligatoire"," merci de remplir tous les champs");
        return;  // permet de ne  pas fermer la boîte de dialogue
    }

    else
    {
        interfaces toto, tata;
        toto.list = new QListWidget(this);
        // tata.formulaire= new Formulaire(this);

       //  avec les fonction get mais c'est un peux plus long
   toto.list->addItem("Nom: " + tata.formulaire->getNom());
   toto.list->addItem("Prénoms: " + tata.formulaire->getPrenoms());
   toto.list->addItem("Âge: " + tata.formulaire->getAge());
   toto.list->addItem("Formation: " + tata.formulaire->getFormation());
   toto.list->show();


    list->addItem("Nom: " + formulaire->valeur_nom->text());
    list->addItem("Prénoms: " + formulaire->valeur_prenoms->text());
    list->addItem("Âge: " + formulaire->valeur_age->text());
    list->addItem("Formation: " + formulaire->valeur_formation->text());

    }
}
*/
