#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QTimer>
#include <QTime>
#include <QPushButton>
#include <QMessageBox>


class MyWidget : public QObject
{
    Q_OBJECT
    bool _isStarted;
    QLabel *_lbl1,*_lbl2,*_lbl3,*_lbl4,*_lbl5;
    QWidget *_wid;
    QTimer *_time,*_alarme,*_chrono;
    QGridLayout *_lay;
    QPushButton *_but1;
    QTime *_timeChrono;
public:
    MyWidget(QObject* parent = nullptr);
    void Show();
public slots:
    void setTime();
    void Alarme();
    void Chrono();
    void setTimeChrono();
};

#endif // MYWIDGET_H
