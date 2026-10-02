#ifndef INTERFACES_H
#define INTERFACES_H

#include <QApplication>
#include <QWidget>
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
#include <QDialog>
#include "Formulaire.h"

class interfaces : public QWidget
{
    Q_OBJECT
public:
    interfaces(QWidget *parent = nullptr);
    interfaces(const QString&, const QString&, QWidget *parent = nullptr);
    ~interfaces();
    QPushButton*OK;
    QPushButton*cancel;

signals:

public slots:
    void LancerInterfaceFormulaire();
    void quitter();
    void Suprimer();
    void toutSuprimer();

public:
    QListWidget*list;
    QPushButton*form;
    QPushButton*quit;
    //QLayout*layout;
    Formulaire*formulaire;

};
#endif // INTERFACES_H






/*
Ajouter un élément:	listWidget->addItem("Élément");
Ajouter plusieurs éléments:	listWidget->addItems({"A", "B", "C"});
Récupérer l’élément sélectionné:	QString txt = listWidget->currentItem()->text();
Modifier le texte d’un élément:	listWidget->currentItem()->setText("Nouveau texte");
Supprimer l’élément sélectionné:	delete listWidget->currentItem();
Supprimer tous les éléments:	listWidget->clear();
Détecter un clic(connection):	connect(listWidget, &QListWidget::itemClicked, this, &MainWindow::onItemClicked);
Ajouter une icône:	listWidget->addItem(new QListWidgetItem(QIcon("icon.png"), "Texte"));
Sélection multiple:	listWidget->setSelectionMode(QAbstractItemView::MultiSelection);
 */
