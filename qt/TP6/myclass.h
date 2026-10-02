#ifndef MYCLASS_H
#define MYCLASS_H

#include <QMainWindow>
#include <QWidget>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QMdiArea>
#include <QMenuBar>
#include <QAction>
#include <QApplication>
#include <QMessageBox>
#include <QMdiSubWindow>
#include <QLabel>
#include <QPixmap>
#include <QLineEdit>
#include <QFormLayout>


class MYCLASS: public QMainWindow
{
     Q_OBJECT
public:
    MYCLASS();



private:


    //QWidget *MDI;   // Pour SDI
    QWidget* MDI_W;
    QMdiArea *MDI;
    QTextEdit *m_pText;
    QHBoxLayout *layout;

    QMenu *menuFichier, *menuEdition, *menuAide,*menu ;
    QAction *actionNouveau,*actionOuvrir,*actionQuitter, *actionFichier,*actionEdition, *actionAide, *actionAfficherImage;
    QAction *actionCopier,*actionColler;
    QAction *actionApropos;

    QLineEdit *nom;
    QLineEdit *prenom;
    QLineEdit *age;
    QFormLayout *Layout;




signals:


public slots:
    void AfficherImage();
    void Aide();
    void Ouvrir();
    void Copier();
    void Coller();
    void Nouveau();
};

#ifndef MYMDIAREA_H
#define MYMDIAREA_H

#include <QMdiArea>
#include <QPixmap>

class MyMdiArea : public QMdiArea
{
    Q_OBJECT

public:
    explicit MyMdiArea(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QPixmap backgroundPixmap;
};

#endif // MYMDIAREA_H


#endif // MYCLASS_H

