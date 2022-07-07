/********************************************************************************
** Form generated from reading UI file 'register.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER_H
#define UI_REGISTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Register
{
public:
    QPushButton *id_check;
    QPushButton *reg_Btn;
    QLineEdit *id_text;
    QLineEdit *pw_text;
    QLineEdit *ck_pw_text;
    QLineEdit *name;
    QPushButton *ck_pw_Btn;

    void setupUi(QDialog *Register)
    {
        if (Register->objectName().isEmpty())
            Register->setObjectName(QString::fromUtf8("Register"));
        Register->resize(400, 300);
        id_check = new QPushButton(Register);
        id_check->setObjectName(QString::fromUtf8("id_check"));
        id_check->setGeometry(QRect(280, 60, 89, 25));
        reg_Btn = new QPushButton(Register);
        reg_Btn->setObjectName(QString::fromUtf8("reg_Btn"));
        reg_Btn->setEnabled(false);
        reg_Btn->setGeometry(QRect(160, 220, 89, 25));
        id_text = new QLineEdit(Register);
        id_text->setObjectName(QString::fromUtf8("id_text"));
        id_text->setGeometry(QRect(150, 60, 113, 24));
        pw_text = new QLineEdit(Register);
        pw_text->setObjectName(QString::fromUtf8("pw_text"));
        pw_text->setEnabled(false);
        pw_text->setGeometry(QRect(150, 100, 113, 24));
        ck_pw_text = new QLineEdit(Register);
        ck_pw_text->setObjectName(QString::fromUtf8("ck_pw_text"));
        ck_pw_text->setEnabled(false);
        ck_pw_text->setGeometry(QRect(150, 140, 113, 24));
        name = new QLineEdit(Register);
        name->setObjectName(QString::fromUtf8("name"));
        name->setEnabled(false);
        name->setGeometry(QRect(150, 180, 113, 24));
        ck_pw_Btn = new QPushButton(Register);
        ck_pw_Btn->setObjectName(QString::fromUtf8("ck_pw_Btn"));
        ck_pw_Btn->setEnabled(false);
        ck_pw_Btn->setGeometry(QRect(280, 140, 89, 25));

        retranslateUi(Register);

        QMetaObject::connectSlotsByName(Register);
    } // setupUi

    void retranslateUi(QDialog *Register)
    {
        Register->setWindowTitle(QCoreApplication::translate("Register", "Dialog", nullptr));
        id_check->setText(QCoreApplication::translate("Register", "\354\244\221\353\263\265\355\231\225\354\235\270", nullptr));
        reg_Btn->setText(QCoreApplication::translate("Register", "\352\260\200\354\236\205", nullptr));
        ck_pw_Btn->setText(QCoreApplication::translate("Register", "\353\271\204\353\260\200\353\262\210\355\230\270 \355\231\225\354\235\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Register: public Ui_Register {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER_H
