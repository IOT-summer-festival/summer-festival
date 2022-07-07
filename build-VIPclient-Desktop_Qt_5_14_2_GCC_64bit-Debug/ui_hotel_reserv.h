/********************************************************************************
** Form generated from reading UI file 'hotel_reserv.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOTEL_RESERV_H
#define UI_HOTEL_RESERV_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_hotel_reserv
{
public:
    QListWidget *list;
    QPushButton *slt;
    QPushButton *cancel;

    void setupUi(QDialog *hotel_reserv)
    {
        if (hotel_reserv->objectName().isEmpty())
            hotel_reserv->setObjectName(QString::fromUtf8("hotel_reserv"));
        hotel_reserv->resize(320, 343);
        list = new QListWidget(hotel_reserv);
        list->setObjectName(QString::fromUtf8("list"));
        list->setGeometry(QRect(10, 10, 291, 291));
        slt = new QPushButton(hotel_reserv);
        slt->setObjectName(QString::fromUtf8("slt"));
        slt->setGeometry(QRect(10, 300, 141, 31));
        cancel = new QPushButton(hotel_reserv);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setGeometry(QRect(150, 300, 151, 31));

        retranslateUi(hotel_reserv);

        QMetaObject::connectSlotsByName(hotel_reserv);
    } // setupUi

    void retranslateUi(QDialog *hotel_reserv)
    {
        hotel_reserv->setWindowTitle(QCoreApplication::translate("hotel_reserv", "Dialog", nullptr));
        slt->setText(QCoreApplication::translate("hotel_reserv", "\354\204\240\355\203\235", nullptr));
        cancel->setText(QCoreApplication::translate("hotel_reserv", "\355\230\270\355\205\224 \354\267\250\354\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class hotel_reserv: public Ui_hotel_reserv {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOTEL_RESERV_H
