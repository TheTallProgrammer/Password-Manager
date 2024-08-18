/********************************************************************************
** Form generated from reading UI file 'resetpassword.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESETPASSWORD_H
#define UI_RESETPASSWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_resetPassword
{
public:
    QLineEdit *passEntryOne;
    QLineEdit *passEntryTwo;
    QLabel *label;
    QLabel *label_2;
    QPushButton *cancelButton;
    QPushButton *confirmButton;

    void setupUi(QDialog *resetPassword)
    {
        if (resetPassword->objectName().isEmpty())
            resetPassword->setObjectName("resetPassword");
        resetPassword->resize(800, 600);
        passEntryOne = new QLineEdit(resetPassword);
        passEntryOne->setObjectName("passEntryOne");
        passEntryOne->setGeometry(QRect(10, 190, 781, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Bahnschrift Light")});
        font.setPointSize(13);
        passEntryOne->setFont(font);
        passEntryOne->setAlignment(Qt::AlignmentFlag::AlignCenter);
        passEntryTwo = new QLineEdit(resetPassword);
        passEntryTwo->setObjectName("passEntryTwo");
        passEntryTwo->setGeometry(QRect(10, 340, 781, 51));
        passEntryTwo->setFont(font);
        passEntryTwo->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label = new QLabel(resetPassword);
        label->setObjectName("label");
        label->setGeometry(QRect(250, 140, 321, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Bahnschrift Light")});
        font1.setPointSize(22);
        label->setFont(font1);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_2 = new QLabel(resetPassword);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(240, 300, 341, 41));
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        cancelButton = new QPushButton(resetPassword);
        cancelButton->setObjectName("cancelButton");
        cancelButton->setGeometry(QRect(160, 480, 191, 101));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Bahnschrift Light")});
        font2.setPointSize(25);
        cancelButton->setFont(font2);
        confirmButton = new QPushButton(resetPassword);
        confirmButton->setObjectName("confirmButton");
        confirmButton->setGeometry(QRect(430, 480, 191, 101));
        confirmButton->setFont(font2);

        retranslateUi(resetPassword);

        QMetaObject::connectSlotsByName(resetPassword);
    } // setupUi

    void retranslateUi(QDialog *resetPassword)
    {
        resetPassword->setWindowTitle(QCoreApplication::translate("resetPassword", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("resetPassword", "Enter New Password:", nullptr));
        label_2->setText(QCoreApplication::translate("resetPassword", "Re-Enter New Password:", nullptr));
        cancelButton->setText(QCoreApplication::translate("resetPassword", "Cancel", nullptr));
        confirmButton->setText(QCoreApplication::translate("resetPassword", "Confirm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class resetPassword: public Ui_resetPassword {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESETPASSWORD_H
