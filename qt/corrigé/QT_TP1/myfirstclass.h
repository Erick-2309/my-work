#ifndef MYFIRSTCLASS_H
#define MYFIRSTCLASS_H

#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QMessageBox>

class MyFirstClass : public QWidget
{
    Q_OBJECT
public:
    MyFirstClass(QWidget *parent = 0);
    MyFirstClass(char *TextBouton, char *textTextEdit,QWidget *parent=0);

signals:

public slots:
};

#endif // MYFIRSTCLASS_H
