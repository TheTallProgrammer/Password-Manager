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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_passwordManagementButtons
{
public:
    QPushButton *storePass;
    QPushButton *retrievePass;
    QPushButton *genPass;
    QPushButton *exportPassButton;
    QPushButton *resetLoginButton;
    QPushButton *deleteAllButton;
    QPushButton *logoutButton;
    QWidget *themeWidget;

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
        storePass->setGeometry(QRect(20, 130, 330, 100));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Bahnschrift Light")});
        font1.setPointSize(23);
        storePass->setFont(font1);
        retrievePass = new QPushButton(passwordManagementButtons);
        retrievePass->setObjectName("retrievePass");
        retrievePass->setGeometry(QRect(20, 260, 330, 100));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Bahnschrift Light")});
        font2.setPointSize(21);
        retrievePass->setFont(font2);
        genPass = new QPushButton(passwordManagementButtons);
        genPass->setObjectName("genPass");
        genPass->setGeometry(QRect(20, 390, 330, 100));
        genPass->setFont(font1);
        exportPassButton = new QPushButton(passwordManagementButtons);
        exportPassButton->setObjectName("exportPassButton");
        exportPassButton->setGeometry(QRect(450, 260, 330, 100));
        exportPassButton->setFont(font1);
        resetLoginButton = new QPushButton(passwordManagementButtons);
        resetLoginButton->setObjectName("resetLoginButton");
        resetLoginButton->setGeometry(QRect(450, 130, 330, 100));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Bahnschrift Light")});
        font3.setPointSize(22);
        resetLoginButton->setFont(font3);
        deleteAllButton = new QPushButton(passwordManagementButtons);
        deleteAllButton->setObjectName("deleteAllButton");
        deleteAllButton->setGeometry(QRect(450, 390, 330, 100));
        deleteAllButton->setFont(font1);
        logoutButton = new QPushButton(passwordManagementButtons);
        logoutButton->setObjectName("logoutButton");
        logoutButton->setGeometry(QRect(19, 523, 761, 61));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Bahnschrift Light")});
        font4.setPointSize(24);
        logoutButton->setFont(font4);
        themeWidget = new QWidget(passwordManagementButtons);
        themeWidget->setObjectName("themeWidget");
        themeWidget->setGeometry(QRect(270, 10, 261, 80));

        retranslateUi(passwordManagementButtons);

        QMetaObject::connectSlotsByName(passwordManagementButtons);
    } // setupUi

    void retranslateUi(QDialog *passwordManagementButtons)
    {
        passwordManagementButtons->setWindowTitle(QCoreApplication::translate("passwordManagementButtons", "Dialog", nullptr));
        storePass->setText(QCoreApplication::translate("passwordManagementButtons", "Add New Password", nullptr));
        retrievePass->setText(QCoreApplication::translate("passwordManagementButtons", "View/Manage passwords", nullptr));
        genPass->setText(QCoreApplication::translate("passwordManagementButtons", "Password Generator", nullptr));
        exportPassButton->setText(QCoreApplication::translate("passwordManagementButtons", "Export Passwords", nullptr));
        resetLoginButton->setText(QCoreApplication::translate("passwordManagementButtons", "Change Login Password", nullptr));
        deleteAllButton->setText(QCoreApplication::translate("passwordManagementButtons", "Erase All Data", nullptr));
        logoutButton->setText(QCoreApplication::translate("passwordManagementButtons", "Logout", nullptr));
    } // retranslateUi

};

namespace Ui {
    class passwordManagementButtons: public Ui_passwordManagementButtons {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORDMANAGEMENTBUTTONS_H
