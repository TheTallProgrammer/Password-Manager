/********************************************************************************
** Form generated from reading UI file 'passwordmanagementbuttons.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSWORDMANAGEMENTBUTTONS_H
#define UI_PASSWORDMANAGEMENTBUTTONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_passwordManagementButtons
{
public:
    QPushButton *storePass;
    QPushButton *retrievePass;
    QPushButton *genPass;

    void setupUi(QDialog *passwordManagementButtons)
    {
        if (passwordManagementButtons->objectName().isEmpty())
            passwordManagementButtons->setObjectName("passwordManagementButtons");
        passwordManagementButtons->resize(800, 600);
        QFont font;
        font.setFamilies({QString::fromUtf8("Yu Gothic Medium")});
        font.setPointSize(26);
        passwordManagementButtons->setFont(font);
        storePass = new QPushButton(passwordManagementButtons);
        storePass->setObjectName("storePass");
        storePass->setGeometry(QRect(200, 60, 400, 100));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Bahnschrift Light")});
        font1.setPointSize(26);
        storePass->setFont(font1);
        retrievePass = new QPushButton(passwordManagementButtons);
        retrievePass->setObjectName("retrievePass");
        retrievePass->setGeometry(QRect(200, 240, 400, 100));
        retrievePass->setFont(font1);
        genPass = new QPushButton(passwordManagementButtons);
        genPass->setObjectName("genPass");
        genPass->setGeometry(QRect(200, 420, 400, 100));
        genPass->setFont(font1);

        retranslateUi(passwordManagementButtons);

        QMetaObject::connectSlotsByName(passwordManagementButtons);
    } // setupUi

    void retranslateUi(QDialog *passwordManagementButtons)
    {
        passwordManagementButtons->setWindowTitle(QCoreApplication::translate("passwordManagementButtons", "Dialog", nullptr));
        storePass->setText(QCoreApplication::translate("passwordManagementButtons", "Store Password", nullptr));
        retrievePass->setText(QCoreApplication::translate("passwordManagementButtons", "Retrieve Password", nullptr));
        genPass->setText(QCoreApplication::translate("passwordManagementButtons", "Generate Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class passwordManagementButtons: public Ui_passwordManagementButtons {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORDMANAGEMENTBUTTONS_H
