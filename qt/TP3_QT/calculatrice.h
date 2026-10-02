#ifndef CALCULATRICE_H
#define CALCULATRICE_H
#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QtMath>
#include <QPushButton>
#include <QHBoxLayout>
# include <QApplication>
#include <QComboBox>
#include <QFormLayout>

class calculatrice : public QWidget
{
    Q_OBJECT
public:
    calculatrice(const QString&, const QString&, QWidget*parent=nullptr);
    calculatrice();
    void calcul();

private:
    QComboBox*m_combo;
    QLineEdit*m_le1;
    QLineEdit*m_le2;
    QLineEdit*m_le3;
    QPushButton*m_pb1;
    QPushButton*m_pb2;
    QLayout*m_layout;

};

#endif // CALCULATRICE_H
