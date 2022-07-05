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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_reservation
{
public:
    QCalendarWidget *calendar;
    QPushButton *pushButton;
    QCheckBox *guide;
    QCheckBox *sleep;

    void setupUi(QDialog *reservation)
    {
        if (reservation->objectName().isEmpty())
            reservation->setObjectName(QString::fromUtf8("reservation"));
        reservation->resize(750, 500);
        reservation->setMinimumSize(QSize(750, 500));
        reservation->setMaximumSize(QSize(750, 500));
        calendar = new QCalendarWidget(reservation);
        calendar->setObjectName(QString::fromUtf8("calendar"));
        calendar->setGeometry(QRect(160, 70, 411, 281));
        calendar->setStyleSheet(QString::fromUtf8(""));
        calendar->setGridVisible(false);
        calendar->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
        calendar->setNavigationBarVisible(true);
        calendar->setDateEditEnabled(true);
        pushButton = new QPushButton(reservation);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(410, 360, 141, 51));
        guide = new QCheckBox(reservation);
        guide->setObjectName(QString::fromUtf8("guide"));
        guide->setGeometry(QRect(317, 370, 81, 22));
        sleep = new QCheckBox(reservation);
        sleep->setObjectName(QString::fromUtf8("sleep"));
        sleep->setGeometry(QRect(240, 370, 78, 22));

        retranslateUi(reservation);

        QMetaObject::connectSlotsByName(reservation);
    } // setupUi

    void retranslateUi(QDialog *reservation)
    {
        reservation->setWindowTitle(QCoreApplication::translate("reservation", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("reservation", "\354\230\210\354\225\275\355\225\230\352\270\260", nullptr));
        guide->setText(QCoreApplication::translate("reservation", "\352\260\200\354\235\264\353\223\234", nullptr));
        sleep->setText(QCoreApplication::translate("reservation", "\354\210\231\353\260\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class reservation: public Ui_reservation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESERVATION_H
