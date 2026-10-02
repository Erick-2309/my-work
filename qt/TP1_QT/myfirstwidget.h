#ifndef MYFIRSTWIDGET_H
#define MYFIRSTWIDGET_H
#include <QMainWindow>
#include <QApplication>
#include <QPushButton>
#include <QFont>
#include <QTextEdit>
#include <QLineEdit>
#include <QFormLayout>
#include <QWidget>
#include <QHBoxLayout>  // Layout horizontal
#include <QVBoxLayout>  // Layout vertical
#include <QGridLayout>  // Layout en grille



class MyFirstWidget: public QWidget
{
    Q_OBJECT
private:
    //QPushButton*m_button;
    //QTextEdit*m_text;
    //QLayout*m_layout;
    //QWidget*m_window;
public:
    MyFirstWidget(QWidget *parent = 0);
    MyFirstWidget(const QString&TextBouton,const QString&textTextEdit, QWidget *parent=0);
    void showWindow();
    ~MyFirstWidget();


    //MyFirstWidget(const QString& , const QString& , QWidget*parent);

};

#endif // MYFIRSTWIDGET_H

/*
MyFirstWidget(const MyFirstWidget &);
MyFirstWidget(MyFirstWidget &&);
MyFirstWidget &operator=(const MyFirstWidget &);
MyFirstWidget &operator=(MyFirstWidget &&);
*/












/*

#ifndef MYFIRSTWIDGET_H
#define MYFIRSTWIDGET_H

#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>

class MyFirstWidgetData;

class MyFirstWidget
{
    Q_OBJECT
    QML_ELEMENT
public:
    MyFirstWidget();
    MyFirstWidget(const MyFirstWidget &);
    MyFirstWidget(MyFirstWidget &&);
    MyFirstWidget &operator=(const MyFirstWidget &);
    MyFirstWidget &operator=(MyFirstWidget &&);
    ~MyFirstWidget();

private:
    QSharedDataPointer<MyFirstWidgetData> data;
};

#endif // MYFIRSTWIDGET_H    */
