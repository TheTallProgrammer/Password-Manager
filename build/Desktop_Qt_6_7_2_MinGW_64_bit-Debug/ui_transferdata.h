/********************************************************************************
** Form generated from reading UI file 'transferdata.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRANSFERDATA_H
#define UI_TRANSFERDATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_transferData
{
public:
    QPushButton *importButton;
    QPushButton *exportButton;
    QPushButton *backButton;

    void setupUi(QDialog *transferData)
    {
        if (transferData->objectName().isEmpty())
            transferData->setObjectName("transferData");
        transferData->resize(800, 600);
        importButton = new QPushButton(transferData);
        importButton->setObjectName("importButton");
        importButton->setGeometry(QRect(190, 120, 451, 81));
        QFont font;
        font.setFamilies({QString::fromUtf8("Bahnschrift Light")});
        font.setPointSize(26);
        importButton->setFont(font);
        exportButton = new QPushButton(transferData);
        exportButton->setObjectName("exportButton");
        exportButton->setGeometry(QRect(190, 310, 451, 81));
        exportButton->setFont(font);
        backButton = new QPushButton(transferData);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(320, 490, 181, 81));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Bahnschrift Light")});
        font1.setPointSize(27);
        backButton->setFont(font1);

        retranslateUi(transferData);

        QMetaObject::connectSlotsByName(transferData);
    } // setupUi

    void retranslateUi(QDialog *transferData)
    {
        transferData->setWindowTitle(QCoreApplication::translate("transferData", "Dialog", nullptr));
        importButton->setText(QCoreApplication::translate("transferData", "Import Passwords", nullptr));
        exportButton->setText(QCoreApplication::translate("transferData", "Export Passwords", nullptr));
        backButton->setText(QCoreApplication::translate("transferData", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class transferData: public Ui_transferData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRANSFERDATA_H
