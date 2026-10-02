#ifndef MYCLASS_H
#define MYCLASS_H

#include <QMainWindow>
//#include <QtWidgets>
#include <QTextEdit>
#include <QHBoxLayout>
#include<QMdiArea>
#include<QMenuBar>
#include<QAction>
#include<QApplication>
#include <QMessageBox>
#include <QMdiSubWindow>

class MyClass: public QMainWindow
{
    Q_OBJECT

public:
    MyClass();
private:
    //QWidget *MDI;   // Pour SDI
    QWidget* MDI_W;
    QMdiArea *MDI;
    QTextEdit *m_pText;
    QHBoxLayout *layout;

    QMenu *menuFichier, *menuEdition, *menuAide;
    QAction *actionNouveau,*actionOuvrir,*actionQuitter;
    QAction *actionCopier,*actionColler;
    QAction *actionApropos;

signals:

public slots:
    void Aide();
    void Ouvrir();
    void Copier();
    void Coller();
    void Nouveau();
};

#endif // MYCLASS_H
