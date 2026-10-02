#include "mywidget.h"
#define alarme 10000
MyWidget::MyWidget(QObject* parent) :QObject(parent)
{
    _isStarted = false;
    _lbl1 = new QLabel("HEURE");
    _lbl2 = new QLabel(QTime::currentTime().toString("hh:mm:ss"));
    _lbl3 = new QLabel("ALARME");
    _lbl4 = new QLabel(QTime::currentTime().addMSecs(alarme).toString("hh:mm:ss"));
    _lbl5 = new QLabel();
    _wid = new QWidget();
    _lay = new QGridLayout();
    _time = new QTimer();
    _alarme = new QTimer();
    _chrono = new QTimer();
    _but1 = new QPushButton("TOP");
    _timeChrono = new QTime(QTime::fromString("00:00:00"));

    _lay->addWidget(_lbl1);
    _lay->addWidget(_lbl2,0,1);
    _lay->addWidget(_lbl3,1,0);
    _lay->addWidget(_lbl4,1,1);
    _lay->addWidget(_but1,2,0);
    _lay->addWidget(_lbl5,2,1);

    _wid->setLayout((_lay));
    _time->setInterval(1000);
    _time->start();
    _alarme->setInterval(alarme);
    _alarme->start();
    _chrono->setInterval(1000);
    QObject::connect(_time,SIGNAL(timeout()),this,SLOT(setTime()));
    QObject::connect(_alarme,SIGNAL(timeout()),this,SLOT(Alarme()));
    QObject::connect(_but1,SIGNAL(clicked(bool)),this,SLOT(Chrono()));
    QObject::connect(_chrono,SIGNAL(timeout()),this,SLOT(setTimeChrono()));

}
void MyWidget::Show()
{
    _wid->show();
}
void MyWidget::setTime()
{
    _lbl2->setText(QTime::currentTime().toString("hh:mm:ss"));
}
void MyWidget::Alarme()
{
    QMessageBox::information(_wid,"Alarme","L'alarme s'est declenchée",QMessageBox::Ok);
    _alarme->stop();
}
void MyWidget::Chrono()
{
    if(!_isStarted)
    {
        _chrono->start();
        _but1->setText("PAUSE");
        _isStarted = true;
    }
    else
    {
        _chrono->stop();
        _but1->setText("TOP");
        _isStarted = false;
    }
}
void MyWidget::setTimeChrono()
{
    (*_timeChrono) = _timeChrono->addSecs(1);
    _lbl5->setText(_timeChrono->toString("hh:mm:ss"));
}
