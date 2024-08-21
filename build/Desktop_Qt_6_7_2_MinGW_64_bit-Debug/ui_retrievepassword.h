/********************************************************************************
** Form generated from reading UI file 'retrievepassword.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RETRIEVEPASSWORD_H
#define UI_RETRIEVEPASSWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_retrievePassword
{
public:
    QTableWidget *tableWidget;
    QPushButton *backButton;

    void setupUi(QDialog *retrievePassword)
    {
        if (retrievePassword->objectName().isEmpty())
            retrievePassword->setObjectName("retrievePassword");
        retrievePassword->resize(800, 600);
        tableWidget = new QTableWidget(retrievePassword);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(0, 0, 800, 531));
        backButton = new QPushButton(retrievePassword);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(10, 540, 131, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Bahnschrift Light")});
        font.setPointSize(18);
        backButton->setFont(font);

        retranslateUi(retrievePassword);

        QMetaObject::connectSlotsByName(retrievePassword);
    } // setupUi

    void retranslateUi(QDialog *retrievePassword)
    {
        retrievePassword->setWindowTitle(QCoreApplication::translate("retrievePassword", "Dialog", nullptr));
        backButton->setText(QCoreApplication::translate("retrievePassword", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class retrievePassword: public Ui_retrievePassword {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RETRIEVEPASSWORD_H
