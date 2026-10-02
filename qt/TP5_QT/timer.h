#ifndef TIMER_H
#define TIMER_H

#include <QWidget>
#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QTimeEdit>
#include <QTimer>
#include <QTime>
#include <QPushButton>
#include <QMessageBox>

class Timer : public QWidget
{
    Q_OBJECT
public:
    explicit Timer(QWidget *parent = nullptr);

    QLabel*heure,*heure_value;
    QLabel*alarme,*chrono_value;
    QTimeEdit*alarme_value;
    QTimer*timer,*alarme_timer,*chrono_timer;
    QTime*chrono_time;
    QPushButton*chrono_buton;
    QPushButton*reset;


    bool lancer;

public slots:
    void mise_a_jour_heur();
    void gerer_alarme();
    void lancer_chrono();
    void mise_a_jour_chrono();
    void mise_a_zero();


signals:
    // timeout() temps d'attente
};

#endif // TIMER_H
