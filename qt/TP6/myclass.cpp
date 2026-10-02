

 #include "myclass.h"
 #include <QtGui/qpainter.h>




MYCLASS ::MYCLASS()

{

    //Création d'une application de type MDI

    MDI = new QMdiArea;




    //MDI_W=new QWidget();


    m_pText = new QTextEdit(this);
    m_pText->setText("SDI");
    m_pText->setFont(QFont("Arial",12));
    m_pText->setStyleSheet("bacground-color:yello");

    layout = new QHBoxLayout;



    QLineEdit *nom = new QLineEdit;
    QLineEdit *prenom = new QLineEdit;
    QLineEdit *age = new QLineEdit;
    QFormLayout *Layout = new QFormLayout;


    Layout->addRow("Votre nom", nom);
    Layout->addRow("Votre prénom", prenom);
    Layout->addRow("Votre âge", age);

    //  Ajout des menus
    menu = menuBar()->addMenu("&My Application");
    QFont boldFont = menu->font();
    boldFont.setBold(true);
    menu->setFont(boldFont);



    menuFichier = menuBar()->addMenu("&Fichier");
    menuEdition = menuBar()->addMenu("&Edition");
    menuAide = menuBar()->addMenu("&Aide");

    // Création de sous menus pour "Fichier"
    actionNouveau = new QAction("&Nouveau", this);
    actionOuvrir = new QAction("&Ouvrir", this);
    actionQuitter = new QAction("&Quitter", this);

    actionFichier = new QAction("&Fichier", this);
    actionEdition = new QAction("&Edition", this);
    actionAide = new QAction("&Aide", this);

    actionAfficherImage = new QAction("Afficher une image ", this);



    // Ajout de sous menus
    menu->addMenu(menuFichier);
    menu->addMenu(menuEdition);
    menu->addMenu(menuAide);
    menu->addAction(actionAfficherImage);

    menuFichier->addAction(actionNouveau);
    menuFichier->addAction(actionOuvrir);
    menuFichier->addAction(actionQuitter);
    menuFichier->addAction(actionAfficherImage);

    // Création de sous menus pour "Copier"
    actionCopier= new QAction("&Copier", this);
    actionColler= new QAction("&Coller", this);
    // Ajout de sous menus
    menuEdition->addAction(actionCopier);
    menuEdition->addAction(actionColler);

    // Création de sous menus pour "Aide"
    actionApropos= new QAction("&A propos", this);
    // Ajout de sous menus
    menuAide->addAction(actionApropos);

    // Slot actions

    connect(actionQuitter, &QAction::triggered, qApp, &QApplication::quit);
    connect(actionNouveau, &QAction::triggered, this, &MYCLASS::Nouveau);
    connect(actionOuvrir, &QAction::triggered, this, &MYCLASS::Ouvrir);
    connect(actionCopier, &QAction::triggered, this, &MYCLASS::Copier);
    connect(actionColler, &QAction::triggered, this, &MYCLASS::Coller);
    connect(actionApropos, &QAction::triggered, this, &MYCLASS::Aide);
    connect(actionAfficherImage, &QAction::triggered, this, &MYCLASS::AfficherImage);

    // Racourcis clavier
    actionOuvrir->setShortcut(QKeySequence(tr("Ctrl+H")));
    actionCopier->setShortcut(QKeySequence(tr("Ctrl+C")));
    actionColler->setShortcut(QKeySequence(tr("Ctrl+V")));
    actionNouveau->setShortcut(QKeySequence(tr("Ctrl+N")));
    actionQuitter->setShortcut(QKeySequence("Ctrl+Q"));
    actionQuitter->setIcon(QIcon("quitter.png"));
    actionApropos->setShortcut(QKeySequence(tr("Ctrl+O")));
    actionAfficherImage->setShortcut(QKeySequence(tr("Ctrl+I")));


/*
    // Crée un QLabel et charge l’image
    QLabel *imageLabel = new QLabel();
    QPixmap pixmap(":/images/parrot.bmp");

    if (pixmap.isNull()) {
        QMessageBox::warning(this, "Erreur", "Impossible de charger l'image.");
        return;
    }

    imageLabel->setPixmap(pixmap);
    imageLabel->setAlignment(Qt::AlignCenter);


*/
    // Crée une sous-fenêtre MDI
    //QMdiSubWindow *subWindow = new QMdiSubWindow;
    //subWindow->setWidget(imageLabel);
    //subWindow->setWindowTitle("Image");


   // MDI->addSubWindow(subWindow);
    //subWindow->resize(pixmap.size());
    //subWindow->show();
    // Ajout dans la zone centrale



    setCentralWidget(MDI);

    layout->addWidget(m_pText);
    layout->addLayout(Layout,3);
    MDI->setLayout(layout);


    //Pour faire apparaitre le menu dans la fenêtre de l'application
    menuBar()->setNativeMenuBar(false);


}

void MYCLASS::AfficherImage()
{
    // Crée un QLabel et charge l’image
    QLabel *imageLabel = new QLabel();
    QPixmap pixmap(":/images/parrot.bmp");


    if (pixmap.isNull()) {
        QMessageBox::warning(this, "Erreur", "Impossible de charger l'image.");
        return;
    }

    imageLabel->setPixmap(pixmap);
    imageLabel->setAlignment(Qt::AlignCenter);

    // Crée une sous-fenêtre MDI
    QMdiSubWindow *subWindow = new QMdiSubWindow;
    subWindow->setWidget(imageLabel);
    subWindow->setWindowTitle("Image");

    MDI->addSubWindow(subWindow);
    subWindow->resize(pixmap.size());
    subWindow->show();

}


void MYCLASS::Aide()
{
    QMessageBox::information(this,"A propos","C'est une belle application");
}

void MYCLASS::Ouvrir()
{
    QMdiSubWindow *sub = new QMdiSubWindow;
    sub->setWidget(new QTextEdit("Ceci est une fenetre"));
    MDI->addSubWindow(sub)->show();
}

void MYCLASS::Copier()
{
    QTextEdit *edit = qobject_cast<QTextEdit *>(MDI->activeSubWindow()->widget());
    edit->copy();
}

void MYCLASS::Coller()
{
    QTextEdit *edit  = qobject_cast<QTextEdit *>(MDI->activeSubWindow()->widget());
    edit->paste();
}

void MYCLASS::Nouveau()
{
    QMdiSubWindow *sub = new QMdiSubWindow;
    sub->setWidget(new QTextEdit("Nouveau Document"));
    MDI->addSubWindow(sub)->show();
}




//#include "MyMdiArea.h"
#include <QPainter>

MyMdiArea::MyMdiArea(QWidget *parent)
    : QMdiArea(parent),
    backgroundPixmap(":/images/parrot.bmp")
{
    // Optionnel : vérifier que l'image est chargée
    if (backgroundPixmap.isNull()) {
        qWarning("Impossible de charger l'image de fond.");
    }
}

void MyMdiArea::paintEvent(QPaintEvent *event)
{
    QMdiArea::paintEvent(event);

    if (!backgroundPixmap.isNull()) {
        QPainter painter(viewport());
        painter.drawPixmap(rect(), backgroundPixmap);
    }
}

/*
#include "myclass.h"

MYCLASS::MYCLASS()
{
    // Création de l'espace MDI
    MDI = new QMdiArea;

    setCentralWidget(MDI);

    // Création des menus
    menuFichier = menuBar()->addMenu("&Fichier");
    menuEdition = menuBar()->addMenu("&Edition");
    menuAide = menuBar()->addMenu("&Aide");

    // Actions
    actionNouveau = new QAction("&Nouveau", this);
    actionOuvrir = new QAction("&Ouvrir", this);
    actionQuitter = new QAction("&Quitter", this);

    actionCopier = new QAction("&Copier", this);
    actionColler = new QAction("&Coller", this);

    actionApropos = new QAction("&A propos", this);

    // Ajout des actions aux menus
    menuFichier->addAction(actionNouveau);
    menuFichier->addAction(actionOuvrir);
    menuFichier->addSeparator();
    menuFichier->addAction(actionQuitter);

    menuEdition->addAction(actionCopier);
    menuEdition->addAction(actionColler);

    menuAide->addAction(actionApropos);

    // Connexions des actions
    connect(actionQuitter, &QAction::triggered, qApp, &QApplication::quit);
    connect(actionNouveau, &QAction::triggered, this, &MYCLASS::Nouveau);
    connect(actionOuvrir, &QAction::triggered, this, &MYCLASS::Ouvrir);
    connect(actionCopier, &QAction::triggered, this, &MYCLASS::Copier);
    connect(actionColler, &QAction::triggered, this, &MYCLASS::Coller);
    connect(actionApropos, &QAction::triggered, this, &MYCLASS::Aide);

    // Raccourcis
    actionNouveau->setShortcut(QKeySequence("Ctrl+N"));
    actionOuvrir->setShortcut(QKeySequence("Ctrl+O"));
    actionQuitter->setShortcut(QKeySequence("Ctrl+Q"));
    actionCopier->setShortcut(QKeySequence("Ctrl+C"));
    actionColler->setShortcut(QKeySequence("Ctrl+V"));
    actionApropos->setShortcut(QKeySequence("F1"));

    // Pour affichage correct du menu sous macOS
    menuBar()->setNativeMenuBar(false);
}

// Affiche un message "À propos"
void MYCLASS::Aide()
{
    QMessageBox::information(this, "A propos", "C'est une belle application");
}

// Ouvre un document dans une nouvelle sous-fenêtre
void MYCLASS::Ouvrir()
{
    auto *sub = new QMdiSubWindow;
    sub->setWidget(new QTextEdit("Ceci est une fenêtre"));
    MDI->addSubWindow(sub)->show();
}

// Crée un nouveau document
void MYCLASS::Nouveau()
{
    auto *sub = new QMdiSubWindow;
    sub->setWidget(new QTextEdit("Nouveau Document"));
    MDI->addSubWindow(sub)->show();
}

// Copie le texte du sous-document actif
void MYCLASS::Copier()
{
    if (auto *edit = qobject_cast<QTextEdit *>(MDI->activeSubWindow()->widget())) {
        edit->copy();
    }
}

// Colle du texte dans le sous-document actif
void MYCLASS::Coller()
{
    if (auto *edit = qobject_cast<QTextEdit *>(MDI->activeSubWindow()->widget())) {
        edit->paste();
    }
}
*/
