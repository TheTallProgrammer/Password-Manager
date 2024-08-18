/********************************************************************************
** Form generated from reading UI file 'storepassword.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STOREPASSWORD_H
#define UI_STOREPASSWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_storePassword
{
public:
    QLabel *label;
    QLabel *label_2;
    QTextEdit *textEdit_3;
    QTextEdit *textEdit_4;
    QTextEdit *textEdit_5;
    QLabel *label_3;
    QTextEdit *textEdit_6;
    QLabel *label_4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *storePassword)
    {
        if (storePassword->objectName().isEmpty())
            storePassword->setObjectName("storePassword");
        storePassword->resize(800, 600);
        label = new QLabel(storePassword);
        label->setObjectName("label");
        label->setGeometry(QRect(150, 30, 111, 20));
        QFont font;
        font.setFamilies({QString::fromUtf8("Bahnschrift Light")});
        font.setPointSize(13);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_2 = new QLabel(storePassword);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(530, 30, 111, 20));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        textEdit_3 = new QTextEdit(storePassword);
        textEdit_3->setObjectName("textEdit_3");
        textEdit_3->setGeometry(QRect(20, 200, 760, 70));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Bahnschrift Light")});
        font1.setPointSize(12);
        textEdit_3->setFont(font1);
        textEdit_4 = new QTextEdit(storePassword);
        textEdit_4->setObjectName("textEdit_4");
        textEdit_4->setGeometry(QRect(20, 60, 371, 71));
        textEdit_4->setFont(font1);
        textEdit_5 = new QTextEdit(storePassword);
        textEdit_5->setObjectName("textEdit_5");
        textEdit_5->setGeometry(QRect(410, 60, 371, 71));
        textEdit_5->setFont(font1);
        label_3 = new QLabel(storePassword);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(340, 170, 111, 20));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        textEdit_6 = new QTextEdit(storePassword);
        textEdit_6->setObjectName("textEdit_6");
        textEdit_6->setGeometry(QRect(20, 330, 760, 131));
        textEdit_6->setFont(font1);
        label_4 = new QLabel(storePassword);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(340, 300, 111, 20));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        pushButton = new QPushButton(storePassword);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(20, 500, 111, 81));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Bahnschrift Light")});
        font2.setPointSize(19);
        pushButton->setFont(font2);
        pushButton_2 = new QPushButton(storePassword);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(150, 500, 311, 81));
        pushButton_2->setFont(font2);
        pushButton_3 = new QPushButton(storePassword);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(470, 500, 311, 81));
        pushButton_3->setFont(font2);

        retranslateUi(storePassword);

        QMetaObject::connectSlotsByName(storePassword);
    } // setupUi

    void retranslateUi(QDialog *storePassword)
    {
        storePassword->setWindowTitle(QCoreApplication::translate("storePassword", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("storePassword", "Password ID:", nullptr));
        label_2->setText(QCoreApplication::translate("storePassword", "Username: ", nullptr));
        textEdit_3->setHtml(QCoreApplication::translate("storePassword", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Bahnschrift Light'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        textEdit_4->setHtml(QCoreApplication::translate("storePassword", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Bahnschrift Light'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Segoe UI'; font-size:9pt;\"><br /></p></body></html>", nullptr));
        textEdit_5->setHtml(QCoreApplication::translate("storePassword", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Bahnschrift Light'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Segoe UI'; font-size:9pt;\"><br /></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("storePassword", "Password:", nullptr));
        textEdit_6->setHtml(QCoreApplication::translate("storePassword", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Bahnschrift Light'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Segoe UI'; font-size:9pt;\"><br /></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("storePassword", "Thought Bank:", nullptr));
        pushButton->setText(QCoreApplication::translate("storePassword", "Back", nullptr));
        pushButton_2->setText(QCoreApplication::translate("storePassword", "Generate Password", nullptr));
        pushButton_3->setText(QCoreApplication::translate("storePassword", "Store Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class storePassword: public Ui_storePassword {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STOREPASSWORD_H
