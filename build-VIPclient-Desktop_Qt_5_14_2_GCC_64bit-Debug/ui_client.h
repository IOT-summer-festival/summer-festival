/********************************************************************************
** Form generated from reading UI file 'client.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENT_H
#define UI_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_client
{
public:
    QPushButton *refresh;
    QPushButton *visit;
    QPushButton *out;
    QListWidget *list;

    void setupUi(QDialog *client)
    {
        if (client->objectName().isEmpty())
            client->setObjectName(QString::fromUtf8("client"));
        client->resize(750, 500);
        client->setMinimumSize(QSize(750, 500));
        client->setMaximumSize(QSize(750, 500));
        refresh = new QPushButton(client);
        refresh->setObjectName(QString::fromUtf8("refresh"));
        refresh->setGeometry(QRect(100, 370, 471, 25));
        visit = new QPushButton(client);
        visit->setObjectName(QString::fromUtf8("visit"));
        visit->setGeometry(QRect(590, 110, 121, 61));
        out = new QPushButton(client);
        out->setObjectName(QString::fromUtf8("out"));
        out->setGeometry(QRect(610, 270, 89, 25));
        list = new QListWidget(client);
        list->setObjectName(QString::fromUtf8("list"));
        list->setGeometry(QRect(100, 60, 471, 311));

        retranslateUi(client);

        QMetaObject::connectSlotsByName(client);
    } // setupUi

    void retranslateUi(QDialog *client)
    {
        client->setWindowTitle(QCoreApplication::translate("client", "Dialog", nullptr));
        refresh->setText(QCoreApplication::translate("client", "\354\203\210\353\241\234\352\263\240\354\271\250", nullptr));
        visit->setText(QCoreApplication::translate("client", "\352\264\200\352\264\221\354\247\200 \353\260\251\353\254\270 \354\230\210\354\225\275", nullptr));
        out->setText(QCoreApplication::translate("client", "\355\232\214\354\233\220 \355\203\210\355\207\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class client: public Ui_client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
