#include "timer.h"
#define ALARME_DELAY 10000  // l'alarme sonnera dans 10 secondes  (10000 ms)

Timer::Timer(QWidget *parent)
    : QWidget{parent}
{
    this->setWindowTitle("timer");
    this->backgroundRole();

    heure= new QLabel("Heure : ");
    heure_value=new QLabel(QTime::currentTime().toString("hh:mm:ss"));

    alarme= new QLabel("Alarme : ");
    //alarme_value= new QLabel(QTime::currentTime().addMSecs(ALARME_DELAY).toString("hh:mm:ss")); //ajoute 10 000 millisecondes (10 secondes) à l'heure actuelle.
    alarme_value= new QTimeEdit(this);
    alarme_value->setDisplayFormat("hh:mm:ss");

    chrono_buton=new QPushButton("start");
    chrono_value=new QLabel("00:00:00");
    reset=new QPushButton("reset");
/*
    QLayout*layout=new QHBoxLayout();
    layout->setAlignment(Qt::AlignCenter);
    layout->addWidget(heure);
    layout->addWidget(heure_value);

    QLayout*hlayout=new QHBoxLayout();
    hlayout->setAlignment(Qt::AlignCenter);
    hlayout->addWidget(Alarme);
    hlayout->addWidget(alarme_value);

    QVBoxLayout*vlayout =new QVBoxLayout(this);
    vlayout->addLayout(layout);
    vlayout->addLayout(hlayout);

    this->setLayout(vlayout);
*/
    QGridLayout*layout=new QGridLayout(this);
    layout->addWidget(heure);
    layout->addWidget(heure_value,0,1);
    layout->addWidget(alarme,1,0);
    layout->addWidget(alarme_value,1,1);
    layout->addWidget(chrono_buton,2,0);
    layout->addWidget(chrono_value,2,1);
    layout->addWidget(reset,2,2);


    this->setLayout(layout);

    timer=new QTimer(this);
    QObject::connect(timer,&QTimer::timeout,this,&Timer::mise_a_jour_heur);
    timer->start(1000);  //lance TIMER quI déclenche timeout() toutes les 1 seconde  (1000 ms)


    chrono_timer=new QTimer(this);
    QObject::connect(chrono_buton,&QPushButton::clicked,this,&Timer::lancer_chrono);
    QObject::connect(reset,&QPushButton::clicked, this, &Timer::mise_a_zero);
    QObject::connect(chrono_timer,&QTimer::timeout,this,&Timer::mise_a_jour_chrono);
    chrono_time= new QTime(QTime::fromString("00:00:00"));
    //chrono_timer->start(1000);


    alarme_timer=new QTimer(this);
    QObject::connect(alarme_timer,&QTimer::timeout,this,&Timer::gerer_alarme);
    alarme_timer->start(1000);
}


void Timer::mise_a_jour_heur()
{
      heure_value->setText(QTime::currentTime().toString("hh:mm:ss"));
}

void Timer::gerer_alarme()
{
    if(alarme_value->text()==heure_value->text())
    {

        QMessageBox::information(this,"Alarme","C'est l'heure,VAS PRIER",QMessageBox::Ok);
        //alarme_timer->stop();en mettant stop notre alarme est bloque meme si on change l'heure d'activation

    }
   /* while (heure_value->text() == alarme_value->text())
    {
        QMessageBox::information(this, "Alarme", "L'heure de l'alarme est atteinte !");
        alarme_timer->stop();
    }*/
}

void Timer::lancer_chrono()
{
    if(!lancer)
    {
        chrono_timer->start(1000);
        chrono_buton->setText("pause");
        lancer=true;
    }
    else
    {
        chrono_timer->stop();
        chrono_buton->setText("reprendre");
        lancer=false;
    }
}
void Timer::mise_a_jour_chrono()
{

    (*chrono_time) = chrono_time->addSecs(1);
    chrono_value->setText(chrono_time->toString("hh:mm:ss"));

 /*
    int temps=0;
    temps++;
    chrono_value->setText(QString::number(temps)+"sec");*/
}

void Timer:: mise_a_zero()
{
    chrono_value->setText("00:00:00");
    chrono_buton->setText("start");
    chrono_time= new QTime(QTime::fromString("00:00:00"));
    chrono_timer->stop();
}




























/*
#include "timer.h"
#include <QTimer>
#include <QTime>
#include <QMessageBox>
#include <QPushButton>

#define ALARME_DELAY 10000  // 10 secondes

Timer::Timer(QWidget *parent)
    : QWidget{parent}, chronoEnCours(false), tempsChrono(0)
{
    this->setWindowTitle("Timer");

    // Création des labels pour afficher l'heure
    heure = new QLabel("Heure : ");
    heure_value = new QLabel(QTime::currentTime().toString("hh:mm:ss"));

    // Création des labels pour afficher l'alarme
    Alarme = new QLabel("Alarme : ");
    heureAlarme = QTime::currentTime().addMSecs(ALARME_DELAY);
    alarme_value = new QLabel(heureAlarme.toString("hh:mm:ss"));

    // Chronomètre
    chrono_label = new QLabel("Chronomètre : ");
    chrono_value = new QLabel("00:00:00");

    bouton_chrono = new QPushButton("Démarrer Chrono");

    // Création des layouts
    QHBoxLayout* layout_heure = new QHBoxLayout();
    layout_heure->setAlignment(Qt::AlignCenter);
    layout_heure->addWidget(heure);
    layout_heure->addWidget(heure_value);

    QHBoxLayout* layout_alarme = new QHBoxLayout();
    layout_alarme->setAlignment(Qt::AlignCenter);
    layout_alarme->addWidget(Alarme);
    layout_alarme->addWidget(alarme_value);

    QHBoxLayout* layout_chrono = new QHBoxLayout();
    layout_chrono->setAlignment(Qt::AlignCenter);
    layout_chrono->addWidget(chrono_label);
    layout_chrono->addWidget(chrono_value);
    layout_chrono->addWidget(bouton_chrono);

    QVBoxLayout* main_layout = new QVBoxLayout(this);
    main_layout->addLayout(layout_heure);
    main_layout->addLayout(layout_alarme);
    main_layout->addLayout(layout_chrono);

    this->setLayout(main_layout);

    // **1️⃣ Timer pour mettre à jour l'heure et surveiller l'alarme**
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Timer::mettreAJourHeure);
    timer->start(1000); // Mise à jour toutes les 1s

    // **2️⃣ Timer pour le chronomètre**
    chrono_timer = new QTimer(this);
    connect(chrono_timer, &QTimer::timeout, this, &Timer::mettreAJourChrono);

    // **3️⃣ Bouton start/stop du chronomètre**
    connect(bouton_chrono, &QPushButton::clicked, this, &Timer::gererChrono);
}

// **Slot pour mettre à jour l'heure et vérifier l'alarme**
void Timer::mettreAJourHeure()
{
    QTime heureActuelle = QTime::currentTime();
    heure_value->setText(heureActuelle.toString("hh:mm:ss"));

    // Vérifier si l'heure actuelle atteint l'heure de l'alarme
    if (heureActuelle >= heureAlarme && !alarmeDeclenchee)
    {
        QMessageBox::information(this, "Alarme", "L'heure de l'alarme est atteinte !");
        alarmeDeclenchee = true; // Pour éviter plusieurs notifications
    }
}

// **Slot pour démarrer/arrêter le chronomètre**
void Timer::gererChrono()
{
    if (chronoEnCours)
    {
        chrono_timer->stop();
        bouton_chrono->setText("Démarrer Chrono");
    }
    else
    {
        tempsDebutChrono = QTime::currentTime();
        chrono_timer->start(1000); // Mise à jour chaque seconde
        bouton_chrono->setText("Arrêter Chrono");
    }
    chronoEnCours = !chronoEnCours;
}

// **Slot pour mettre à jour le temps du chronomètre**
void Timer::mettreAJourChrono()
{
    int secondesEcoulees = tempsDebutChrono.secsTo(QTime::currentTime());
    QTime tempsAffiche = QTime(0, 0).addSecs(secondesEcoulees);
    chrono_value->setText(tempsAffiche.toString("hh:mm:ss"));
}

 */
