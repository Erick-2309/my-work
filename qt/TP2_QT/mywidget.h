#ifndef MYWIDGET_H
#define MYWIDGET_H

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

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    MyWidget(QWidget *parent = nullptr);
    MyWidget(const QString&, const QString &, QWidget*parent=0);
    ~MyWidget();
signals:


public slots:
    void confirm();

private:
    QPushButton*m_pb;
    QTextEdit*m_te;
    QVBoxLayout*m_layout;

};

#endif // MYWIDGET_H
