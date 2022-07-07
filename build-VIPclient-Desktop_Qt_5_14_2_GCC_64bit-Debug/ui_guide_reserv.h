/********************************************************************************
** Form generated from reading UI file 'guide_reserv.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUIDE_RESERV_H
#define UI_GUIDE_RESERV_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Guide_reserv
{
public:
    QListWidget *list;
    QPushButton *slt;
    QPushButton *cancel;

    void setupUi(QDialog *Guide_reserv)
    {
        if (Guide_reserv->objectName().isEmpty())
            Guide_reserv->setObjectName(QString::fromUtf8("Guide_reserv"));
        Guide_reserv->resize(315, 347);
        list = new QListWidget(Guide_reserv);
        list->setObjectName(QString::fromUtf8("list"));
        list->setGeometry(QRect(10, 10, 291, 291));
        slt = new QPushButton(Guide_reserv);
        slt->setObjectName(QString::fromUtf8("slt"));
        slt->setGeometry(QRect(10, 300, 141, 31));
        cancel = new QPushButton(Guide_reserv);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setGeometry(QRect(150, 300, 151, 31));

        retranslateUi(Guide_reserv);

        QMetaObject::connectSlotsByName(Guide_reserv);
    } // setupUi

    void retranslateUi(QDialog *Guide_reserv)
    {
        Guide_reserv->setWindowTitle(QCoreApplication::translate("Guide_reserv", "Dialog", nullptr));
        slt->setText(QCoreApplication::translate("Guide_reserv", "\354\267\250\354\206\214", nullptr));
        cancel->setText(QCoreApplication::translate("Guide_reserv", "\352\260\200\354\235\264\353\223\234 \354\267\250\354\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Guide_reserv: public Ui_Guide_reserv {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIDE_RESERV_H
