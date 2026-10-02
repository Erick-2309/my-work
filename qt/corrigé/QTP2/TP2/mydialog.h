#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QApplication>
#include <QtGui>
#include <QDebug>

#include <QWidget>
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

class MyDialog : public QDialog
{
    Q_OBJECT
public:
    //MyDialog();
    MyDialog(QWidget *parent=0);
signals:

public slots:
};

#endif // MYDIALOG_H
