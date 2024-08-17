/********************************************************************************
** Form generated from reading UI file 'security.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECURITY_H
#define UI_SECURITY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_Security
{
public:

    void setupUi(QDialog *Security)
    {
        if (Security->objectName().isEmpty())
            Security->setObjectName("Security");
        Security->resize(800, 300);

        retranslateUi(Security);

        QMetaObject::connectSlotsByName(Security);
    } // setupUi

    void retranslateUi(QDialog *Security)
    {
        Security->setWindowTitle(QCoreApplication::translate("Security", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Security: public Ui_Security {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECURITY_H
