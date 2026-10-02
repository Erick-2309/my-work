#ifndef MYWIDGET_H
#define MYWIDGET_H

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
#include <QLCDNumber>
#include <QSlider>

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    MyWidget(QWidget *parent = 0);
    MyWidget(char *TextBouton, char *textTextEdit,QWidget *parent=0);

signals:

public slots:
};

#endif // MYWIDGET_H
