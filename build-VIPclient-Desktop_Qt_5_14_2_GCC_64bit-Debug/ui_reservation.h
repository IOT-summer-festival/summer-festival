/********************************************************************************
** Form generated from reading UI file 'reservation.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESERVATION_H
#define UI_RESERVATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_reservation
{
public:
    QCalendarWidget *calendar;
    QPushButton *pushButton;
    QPushButton *hotel;
    QPushButton *guide;
    QLineEdit *hote_text;
    QLineEdit *guide_text;

    void setupUi(QDialog *reservation)
    {
        if (reservation->objectName().isEmpty())
            reservation->setObjectName(QString::fromUtf8("reservation"));
        reservation->resize(750, 500);
        reservation->setMinimumSize(QSize(750, 500));
        reservation->setMaximumSize(QSize(750, 500));
        calendar = new QCalendarWidget(reservation);
        calendar->setObjectName(QString::fromUtf8("calendar"));
        calendar->setGeometry(QRect(140, 50, 461, 311));
        calendar->setStyleSheet(QString::fromUtf8(""));
        calendar->setGridVisible(false);
        calendar->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
        calendar->setNavigationBarVisible(true);
        calendar->setDateEditEnabled(true);
        pushButton = new QPushButton(reservation);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(450, 370, 141, 71));
        hotel = new QPushButton(reservation);
        hotel->setObjectName(QString::fromUtf8("hotel"));
        hotel->setGeometry(QRect(350, 370, 91, 31));
        guide = new QPushButton(reservation);
        guide->setObjectName(QString::fromUtf8("guide"));
        guide->setGeometry(QRect(350, 410, 91, 31));
        hote_text = new QLineEdit(reservation);
        hote_text->setObjectName(QString::fromUtf8("hote_text"));
        hote_text->setGeometry(QRect(140, 370, 201, 31));
        guide_text = new QLineEdit(reservation);
        guide_text->setObjectName(QString::fromUtf8("guide_text"));
        guide_text->setGeometry(QRect(140, 410, 201, 31));

        retranslateUi(reservation);

        QMetaObject::connectSlotsByName(reservation);
    } // setupUi

    void retranslateUi(QDialog *reservation)
    {
        reservation->setWindowTitle(QCoreApplication::translate("reservation", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("reservation", "\354\230\210\354\225\275\355\225\230\352\270\260", nullptr));
        hotel->setText(QCoreApplication::translate("reservation", "\355\230\270\355\205\224 \354\230\210\354\225\275", nullptr));
        guide->setText(QCoreApplication::translate("reservation", "\352\260\200\354\235\264\353\223\234", nullptr));
        hote_text->setText(QCoreApplication::translate("reservation", "X", nullptr));
        guide_text->setText(QCoreApplication::translate("reservation", "X", nullptr));
    } // retranslateUi

};

namespace Ui {
    class reservation: public Ui_reservation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESERVATION_H
