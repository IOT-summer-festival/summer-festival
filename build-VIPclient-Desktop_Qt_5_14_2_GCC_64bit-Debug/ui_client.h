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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_client
{
public:
    QPushButton *refresh;
    QPushButton *visit;
    QPushButton *info;
    QTableWidget *list;

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
        info = new QPushButton(client);
        info->setObjectName(QString::fromUtf8("info"));
        info->setGeometry(QRect(590, 270, 121, 61));
        list = new QTableWidget(client);
        if (list->columnCount() < 2)
            list->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        list->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        list->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        list->setObjectName(QString::fromUtf8("list"));
        list->setGeometry(QRect(100, 50, 471, 321));
        list->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        list->horizontalHeader()->setStretchLastSection(true);
        list->verticalHeader()->setVisible(false);
        list->verticalHeader()->setCascadingSectionResizes(false);
        list->verticalHeader()->setHighlightSections(false);
        list->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        list->verticalHeader()->setStretchLastSection(false);

        retranslateUi(client);

        QMetaObject::connectSlotsByName(client);
    } // setupUi

    void retranslateUi(QDialog *client)
    {
        client->setWindowTitle(QCoreApplication::translate("client", "Dialog", nullptr));
        refresh->setText(QCoreApplication::translate("client", "\354\203\210\353\241\234\352\263\240\354\271\250", nullptr));
        visit->setText(QCoreApplication::translate("client", "\352\264\200\352\264\221\354\247\200 \353\260\251\353\254\270 \354\230\210\354\225\275", nullptr));
        info->setText(QCoreApplication::translate("client", "\353\202\264 \354\240\225\353\263\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem = list->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("client", "\352\264\200\352\264\221\354\247\200", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = list->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("client", "\354\243\274\354\206\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class client: public Ui_client {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENT_H
