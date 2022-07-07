/********************************************************************************
** Form generated from reading UI file 'change_pw.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGE_PW_H
#define UI_CHANGE_PW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_change_Pw
{
public:
    QPushButton *change_Btn;
    QLineEdit *now_pw;
    QLineEdit *ch_pw;
    QLineEdit *ck_ch_pw;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *change_Pw)
    {
        if (change_Pw->objectName().isEmpty())
            change_Pw->setObjectName(QString::fromUtf8("change_Pw"));
        change_Pw->resize(400, 300);
        change_Btn = new QPushButton(change_Pw);
        change_Btn->setObjectName(QString::fromUtf8("change_Btn"));
        change_Btn->setGeometry(QRect(120, 200, 141, 25));
        now_pw = new QLineEdit(change_Pw);
        now_pw->setObjectName(QString::fromUtf8("now_pw"));
        now_pw->setGeometry(QRect(100, 60, 181, 25));
        ch_pw = new QLineEdit(change_Pw);
        ch_pw->setObjectName(QString::fromUtf8("ch_pw"));
        ch_pw->setGeometry(QRect(100, 110, 181, 25));
        ck_ch_pw = new QLineEdit(change_Pw);
        ck_ch_pw->setObjectName(QString::fromUtf8("ck_ch_pw"));
        ck_ch_pw->setGeometry(QRect(100, 160, 181, 25));
        label = new QLabel(change_Pw);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 140, 131, 17));
        label_2 = new QLabel(change_Pw);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(100, 90, 141, 17));
        label_3 = new QLabel(change_Pw);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(100, 40, 111, 17));

        retranslateUi(change_Pw);

        QMetaObject::connectSlotsByName(change_Pw);
    } // setupUi

    void retranslateUi(QDialog *change_Pw)
    {
        change_Pw->setWindowTitle(QCoreApplication::translate("change_Pw", "Dialog", nullptr));
        change_Btn->setText(QCoreApplication::translate("change_Pw", "\353\271\204\353\260\200\353\262\210\355\230\270 \353\263\200\352\262\275", nullptr));
        label->setText(QCoreApplication::translate("change_Pw", "\353\263\200\352\262\275\355\225\240 \353\271\204\353\260\200\353\262\210\355\230\270 \355\231\225\354\235\270", nullptr));
        label_2->setText(QCoreApplication::translate("change_Pw", "\353\263\200\352\262\275\355\225\240 \353\271\204\353\260\200\353\262\210\355\230\270", nullptr));
        label_3->setText(QCoreApplication::translate("change_Pw", "\355\230\204\354\236\254 \353\271\204\353\260\200\353\262\210\355\230\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class change_Pw: public Ui_change_Pw {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGE_PW_H
