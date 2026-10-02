#ifndef FORMULAIRE_H
#define FORMULAIRE_H

#include <QWidget>
#include <QDialog>
#include <QApplication>
#include <QLabel>
#include <QString>
#include <QPushButton>
#include <QTextEdit>
#include <QLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLineEdit>
#include <QMessageBox>
#include <QListWidget>
#include <QWindow>
#include <QFormLayout>
#include <QDateEdit>


class Formulaire : public QDialog
{
    Q_OBJECT
public:
    explicit Formulaire(QWidget*parent=nullptr);
private:

public:
   QLabel*nom;
   QLabel*prenoms;
   QLabel*age;
   QLabel*formation;
   QLineEdit*valeur_nom;
   QLineEdit*valeur_prenoms;
   QDateEdit*valeur_age;
   QLineEdit*valeur_formation;

   QPushButton*OK;
   QPushButton*cancel;
   //QLayout*Layout;



   QString getNom();
   QString getPrenoms();
   QString getAge();
   QString getFormation();



public slots:



signals:

};

#endif // FORMULAIRE_H
