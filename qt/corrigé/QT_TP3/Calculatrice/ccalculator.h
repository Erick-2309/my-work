#ifndef CCALCULATOR_H
#define CCALCULATOR_H

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
#include <QSpinBox>
#include <QLabel>
#include <QComboBox>


class CCalculator : public QWidget
{
    Q_OBJECT
private:
    //  Label de l'addition uniquement
    //QLabel *m_poperator;

    //  ComboBox pour l'ensemble des opérateurs
    QComboBox *m_pcombo;

    QPushButton *m_pegal;
    QLineEdit *m_pope1;
    QLineEdit *m_pope2;
    QLineEdit *m_presult;

public:
    CCalculator();

public slots:
    void Operation();
};

#endif // CCALCULATOR_H
