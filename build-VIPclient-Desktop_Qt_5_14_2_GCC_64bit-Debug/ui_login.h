/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QWidget *centralwidget;
    QPushButton *login_Btn;
    QPushButton *register_Btn;
    QLineEdit *id_text;
    QLineEdit *pw_text;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QString::fromUtf8("login"));
        login->resize(290, 251);
        centralwidget = new QWidget(login);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        login_Btn = new QPushButton(centralwidget);
        login_Btn->setObjectName(QString::fromUtf8("login_Btn"));
        login_Btn->setGeometry(QRect(130, 120, 89, 25));
        register_Btn = new QPushButton(centralwidget);
        register_Btn->setObjectName(QString::fromUtf8("register_Btn"));
        register_Btn->setGeometry(QRect(30, 120, 89, 25));
        id_text = new QLineEdit(centralwidget);
        id_text->setObjectName(QString::fromUtf8("id_text"));
        id_text->setGeometry(QRect(30, 40, 191, 25));
        pw_text = new QLineEdit(centralwidget);
        pw_text->setObjectName(QString::fromUtf8("pw_text"));
        pw_text->setGeometry(QRect(30, 80, 191, 25));
        login->setCentralWidget(centralwidget);
        menubar = new QMenuBar(login);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 290, 22));
        login->setMenuBar(menubar);
        statusbar = new QStatusBar(login);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        login->setStatusBar(statusbar);

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QMainWindow *login)
    {
        login->setWindowTitle(QCoreApplication::translate("login", "login", nullptr));
        login_Btn->setText(QCoreApplication::translate("login", "login", nullptr));
        register_Btn->setText(QCoreApplication::translate("login", "register", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
