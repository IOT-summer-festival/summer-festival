/********************************************************************************
** Form generated from reading UI file 'my_info.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MY_INFO_H
#define UI_MY_INFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_my_info
{
public:
    QPushButton *change_pw;
    QPushButton *cancel;
    QPushButton *refresh;
    QPushButton *out;
    QTableWidget *list;
    QPushButton *ch_hotel;
    QPushButton *ch_guide;

    void setupUi(QDialog *my_info)
    {
        if (my_info->objectName().isEmpty())
            my_info->setObjectName(QString::fromUtf8("my_info"));
        my_info->resize(750, 500);
        my_info->setMinimumSize(QSize(750, 500));
        my_info->setSizeIncrement(QSize(750, 500));
        change_pw = new QPushButton(my_info);
        change_pw->setObjectName(QString::fromUtf8("change_pw"));
        change_pw->setGeometry(QRect(570, 280, 121, 61));
        cancel = new QPushButton(my_info);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setGeometry(QRect(570, 200, 121, 61));
        refresh = new QPushButton(my_info);
        refresh->setObjectName(QString::fromUtf8("refresh"));
        refresh->setGeometry(QRect(60, 400, 491, 25));
        out = new QPushButton(my_info);
        out->setObjectName(QString::fromUtf8("out"));
        out->setGeometry(QRect(570, 360, 121, 61));
        list = new QTableWidget(my_info);
        if (list->columnCount() < 4)
            list->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        list->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        list->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        list->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        list->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        list->setObjectName(QString::fromUtf8("list"));
        list->setGeometry(QRect(60, 40, 491, 361));
        list->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        list->horizontalHeader()->setStretchLastSection(true);
        list->verticalHeader()->setVisible(false);
        list->verticalHeader()->setCascadingSectionResizes(false);
        list->verticalHeader()->setHighlightSections(false);
        list->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        list->verticalHeader()->setStretchLastSection(false);
        ch_hotel = new QPushButton(my_info);
        ch_hotel->setObjectName(QString::fromUtf8("ch_hotel"));
        ch_hotel->setGeometry(QRect(570, 40, 121, 61));
        ch_guide = new QPushButton(my_info);
        ch_guide->setObjectName(QString::fromUtf8("ch_guide"));
        ch_guide->setGeometry(QRect(570, 120, 121, 61));

        retranslateUi(my_info);

        QMetaObject::connectSlotsByName(my_info);
    } // setupUi

    void retranslateUi(QDialog *my_info)
    {
        my_info->setWindowTitle(QCoreApplication::translate("my_info", "Dialog", nullptr));
        change_pw->setText(QCoreApplication::translate("my_info", "\353\271\204\353\260\200\353\262\210\355\230\270 \353\263\200\352\262\275", nullptr));
        cancel->setText(QCoreApplication::translate("my_info", "\354\230\210\354\225\275 \354\267\250\354\206\214", nullptr));
        refresh->setText(QCoreApplication::translate("my_info", "\354\203\210\353\241\234\352\263\240\354\271\250", nullptr));
        out->setText(QCoreApplication::translate("my_info", "\355\232\214\354\233\220 \355\203\210\355\207\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem = list->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("my_info", "\354\230\210\354\225\275\354\235\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = list->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("my_info", "\352\264\200\352\264\221\354\247\200", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = list->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("my_info", "\355\230\270\355\205\224", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = list->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("my_info", "\352\260\200\354\235\264\353\223\234", nullptr));
        ch_hotel->setText(QCoreApplication::translate("my_info", "\355\230\270\355\205\224 \353\263\200\352\262\275", nullptr));
        ch_guide->setText(QCoreApplication::translate("my_info", "\352\260\200\354\235\264\353\223\234 \353\263\200\352\262\275", nullptr));
    } // retranslateUi

};

namespace Ui {
    class my_info: public Ui_my_info {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MY_INFO_H
