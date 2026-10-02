#include "interfaces.h"

interfaces::interfaces(QWidget* parent) : QWidget(parent)
{

}

interfaces::interfaces(const QString &forme, const QString &quitter, QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("interface-multiple");

    form=new QPushButton("formilaire",this);
    form->setText(forme);

    quit = new QPushButton(" quitter",this);
    quit->setText(quitter);

    list=new QListWidget(this);

    QPushButton* suprimer = new QPushButton("suprimer",this);
    QPushButton* toutsuprimer = new QPushButton("tout suprimer",this);


    QLayout*layout= new QVBoxLayout(this);
    layout->addWidget(form);
    layout->addWidget(list);
    layout->addWidget(suprimer);
    layout->addWidget(toutsuprimer);
    layout->addWidget(quit);

    this->setLayout(layout);
    QObject::connect(form, &QPushButton::clicked, this, &interfaces::LancerInterfaceFormulaire);
    QObject::connect(quit, &QPushButton::clicked, this, &interfaces::quitter);
    QObject::connect(suprimer, &QPushButton::clicked, this, &interfaces::Suprimer);
    QObject::connect(toutsuprimer,&QPushButton::clicked,this,&interfaces::toutSuprimer);

}


void interfaces::LancerInterfaceFormulaire()
{
    formulaire=new Formulaire(this);
    formulaire->setModal(true);
    formulaire->show();
    //formulaire->exec();  // Stoppe la fonction jusqu'à ce que l'interface soit fermée


    //avec les fonction get mais c'est un peux plus long
   // list->addItem("Nom: " + formulaire->getNom());
    //list->addItem("Prénoms: " + formulaire->getPrenoms());
    //list->addItem("Âge: " + formulaire->getAge());
    //list->addItem("Formation: " + formulaire->getFormation());

    if(formulaire->exec() == QDialog::Accepted) // Affiche la boîte et attend la fermeture
    {

        if(formulaire->getNom().isEmpty() || formulaire->getPrenoms().isEmpty() || formulaire->getAge().isEmpty() || formulaire->getFormation().isEmpty())
        {
            QMessageBox::warning(this,"champ obligatoire"," votre formulaire n'a pas été envoyé!! \n" " merci de remplir tous les champs");
            return;  // permet de ne  pas fermer la boîte de dialogue

        }
        else
        {
            list->addItem("Nom: " + formulaire->valeur_nom->text());
            list->addItem("Prénoms: " + formulaire->valeur_prenoms->text());
            list->addItem("Âge: " + formulaire->valeur_age->text());
            list->addItem("Formation: " + formulaire->valeur_formation->text());
            list->show();

        }
    }
    delete formulaire;
}

void interfaces::quitter()
{
    int retour = QMessageBox::question(this,"fermeture","vouler vous quitter cette page ?",QMessageBox::Yes|QMessageBox::No);
    if(retour==QMessageBox::Yes)
    {
        this->close();
    }
}

void interfaces::Suprimer()
{
   QListWidgetItem*selectionner = list->currentItem();
    if(selectionner)
   {
       delete list->takeItem(list->row(selectionner));
   }
}


void interfaces::toutSuprimer()
{
    list->clear();
}

interfaces::~interfaces()
{

}

