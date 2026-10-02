#include "myclass.h"

MyClass::MyClass()
{
 /* Q1, Q2 et Q3
   MDI_W = new QWidget();

    m_pText= new QTextEdit("SDI");
    layout = new QHBoxLayout;
    layout->addWidget(m_pText);
    MDI_W->setLayout(layout);

    setCentralWidget(MDI_W);
*/
    //  Création d'une application de type MDI
    MDI = new QMdiArea;

    // Ajout dans la zone centrale
    setCentralWidget(MDI);

    //  Ajout des menus
    menuFichier = menuBar()->addMenu("&Fichier");
    menuEdition = menuBar()->addMenu("&Edition");
    menuAide = menuBar()->addMenu("&Aide");

    // Création de sous menus pour "Fichier"
    actionNouveau = new QAction("&Nouveau", this);
    actionOuvrir = new QAction("&Ouvrir", this);
    actionQuitter = new QAction("&Quitter", this);
    // Ajout de sous menus
    menuFichier->addAction(actionNouveau);
    menuFichier->addAction(actionOuvrir);
    menuFichier->addAction(actionQuitter);

    // Création de sous menus pour "Copier"
    actionCopier= new QAction("&Copier", this);
    actionColler= new QAction("C&oller", this);
    // Ajout de sous menus
    menuEdition->addAction(actionCopier);
    menuEdition->addAction(actionColler);

     // Création de sous menus pour "Aide"
    actionApropos= new QAction("&A propos", this);
    // Ajout de sous menus
    menuAide->addAction(actionApropos);

     // Slot actions
    QObject::connect(actionQuitter, SIGNAL(triggered()), qApp, SLOT(quit()));
    QObject::connect(actionNouveau,SIGNAL(triggered(bool)),this,SLOT(Nouveau()));
    QObject::connect(actionApropos,SIGNAL(triggered(bool)),this,SLOT(Aide()));
    QObject::connect(actionOuvrir,SIGNAL(triggered(bool)),this,SLOT(Ouvrir()));
    QObject::connect(actionCopier,SIGNAL(triggered(bool)),this,SLOT(Copier()));
    QObject::connect(actionColler,SIGNAL(triggered(bool)),this,SLOT(Coller()));

    // Racourcis clavier
    actionColler->setShortcut(QKeySequence(tr("Ctrl+H")));
    actionCopier->setShortcut(QKeySequence(tr("Ctrl+C")));
    actionColler->setShortcut(QKeySequence(tr("Ctrl+V")));
    actionNouveau->setShortcut(QKeySequence(tr("Ctrl+N")));
    actionQuitter->setShortcut(QKeySequence("Ctrl+Q"));
    actionApropos->setShortcut(QKeySequence(tr("Ctrl+O")));

    // Affichage de la toolbar
    menuBar()->show();

    //Pour faire apparaitre le menu dans la fenêtre de l'application
    menuBar()->setNativeMenuBar(false);
}

void MyClass::Aide()
{
  QMessageBox::information(this,"A propos","C'est une belle application");
}

void MyClass::Ouvrir()
{
    QMdiSubWindow *sub = new QMdiSubWindow;
    sub->setWidget(new QTextEdit("Ceci est une fenetre"));
    MDI->addSubWindow(sub)->show();
}

void MyClass::Copier()
{
    QTextEdit *edit = qobject_cast<QTextEdit *>(MDI->activeSubWindow()->widget());
    edit->copy();
}

void MyClass::Coller()
{
    QTextEdit *edit  = qobject_cast<QTextEdit *>(MDI->activeSubWindow()->widget());
    edit->paste();
}

void MyClass::Nouveau()
{
    QMdiSubWindow *sub = new QMdiSubWindow;
    sub->setWidget(new QTextEdit("Nouveau Document"));
    MDI->addSubWindow(sub)->show();
}


