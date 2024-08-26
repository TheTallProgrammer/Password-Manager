/********************************************************************************
** Form generated from reading UI file 'passwordinfo.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSWORDINFO_H
#define UI_PASSWORDINFO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_passwordInfo
{
public:
    QPushButton *copyButton;
    QLabel *infoLabel;
    QPushButton *acknowledgeButton;

    void setupUi(QDialog *passwordInfo)
    {
        if (passwordInfo->objectName().isEmpty())
            passwordInfo->setObjectName("passwordInfo");
        passwordInfo->resize(800, 600);
        copyButton = new QPushButton(passwordInfo);
        copyButton->setObjectName("copyButton");
        copyButton->setGeometry(QRect(250, 370, 281, 91));
        QFont font;
        font.setFamilies({QString::fromUtf8("Bahnschrift Light")});
        font.setPointSize(18);
        copyButton->setFont(font);
        infoLabel = new QLabel(passwordInfo);
        infoLabel->setObjectName("infoLabel");
        infoLabel->setGeometry(QRect(0, 20, 791, 341));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Bahnschrift Light")});
        font1.setPointSize(20);
        infoLabel->setFont(font1);
        infoLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        infoLabel->setWordWrap(true);
        acknowledgeButton = new QPushButton(passwordInfo);
        acknowledgeButton->setObjectName("acknowledgeButton");
        acknowledgeButton->setGeometry(QRect(110, 500, 561, 71));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Bahnschrift Light")});
        font2.setPointSize(30);
        acknowledgeButton->setFont(font2);

        retranslateUi(passwordInfo);

        QMetaObject::connectSlotsByName(passwordInfo);
    } // setupUi

    void retranslateUi(QDialog *passwordInfo)
    {
        passwordInfo->setWindowTitle(QCoreApplication::translate("passwordInfo", "Dialog", nullptr));
        copyButton->setText(QCoreApplication::translate("passwordInfo", "Copy Login Password", nullptr));
        infoLabel->setText(QCoreApplication::translate("passwordInfo", "Important:\n"
"\n"
"Please save your password securely. Currently, there is no way to reset your password unless you are logged in.\n"
"\n"
"If you forget it, you will be locked out of the manager. I'm currently working on a recovery system, but it's not available yet.\n"
"\n"
"Click Copy Password to save it now.", nullptr));
        acknowledgeButton->setText(QCoreApplication::translate("passwordInfo", "Acknowledge", nullptr));
    } // retranslateUi

};

namespace Ui {
    class passwordInfo: public Ui_passwordInfo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORDINFO_H
