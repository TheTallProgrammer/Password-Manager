/********************************************************************************
** Form generated from reading UI file 'editpassworddata.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITPASSWORDDATA_H
#define UI_EDITPASSWORDDATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_editPasswordData
{
public:
    QPushButton *backButton;
    QPushButton *saveButton;
    QTextEdit *passwordIdEdit;
    QTextEdit *usernameEdit;
    QTextEdit *passwordEdit;
    QTextEdit *thoughtsEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *editPasswordData)
    {
        if (editPasswordData->objectName().isEmpty())
            editPasswordData->setObjectName("editPasswordData");
        editPasswordData->resize(800, 600);
        QFont font;
        font.setFamilies({QString::fromUtf8("Bahnschrift Light")});
        font.setPointSize(20);
        editPasswordData->setFont(font);
        backButton = new QPushButton(editPasswordData);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(210, 520, 161, 71));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Bahnschrift Light")});
        font1.setPointSize(17);
        backButton->setFont(font1);
        saveButton = new QPushButton(editPasswordData);
        saveButton->setObjectName("saveButton");
        saveButton->setGeometry(QRect(410, 520, 161, 71));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Bahnschrift Light")});
        font2.setPointSize(15);
        saveButton->setFont(font2);
        passwordIdEdit = new QTextEdit(editPasswordData);
        passwordIdEdit->setObjectName("passwordIdEdit");
        passwordIdEdit->setGeometry(QRect(50, 30, 691, 70));
        usernameEdit = new QTextEdit(editPasswordData);
        usernameEdit->setObjectName("usernameEdit");
        usernameEdit->setGeometry(QRect(50, 140, 691, 70));
        passwordEdit = new QTextEdit(editPasswordData);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setGeometry(QRect(50, 250, 691, 70));
        thoughtsEdit = new QTextEdit(editPasswordData);
        thoughtsEdit->setObjectName("thoughtsEdit");
        thoughtsEdit->setGeometry(QRect(50, 370, 691, 131));
        label = new QLabel(editPasswordData);
        label->setObjectName("label");
        label->setGeometry(QRect(310, 0, 181, 31));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_2 = new QLabel(editPasswordData);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(310, 110, 181, 31));
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_3 = new QLabel(editPasswordData);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(310, 220, 181, 31));
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_4 = new QLabel(editPasswordData);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(310, 340, 181, 31));
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        retranslateUi(editPasswordData);

        QMetaObject::connectSlotsByName(editPasswordData);
    } // setupUi

    void retranslateUi(QDialog *editPasswordData)
    {
        editPasswordData->setWindowTitle(QCoreApplication::translate("editPasswordData", "Dialog", nullptr));
        backButton->setText(QCoreApplication::translate("editPasswordData", "Back", nullptr));
        saveButton->setText(QCoreApplication::translate("editPasswordData", "Save Changes", nullptr));
        label->setText(QCoreApplication::translate("editPasswordData", "Password ID", nullptr));
        label_2->setText(QCoreApplication::translate("editPasswordData", "Username", nullptr));
        label_3->setText(QCoreApplication::translate("editPasswordData", "Password", nullptr));
        label_4->setText(QCoreApplication::translate("editPasswordData", "Thoughts", nullptr));
    } // retranslateUi

};

namespace Ui {
    class editPasswordData: public Ui_editPasswordData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITPASSWORDDATA_H
