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
    QTextEdit *passwordText;
    QTextEdit *passIdText;
    QTextEdit *userText;
    QLabel *label_3;
    QTextEdit *thoughtText;
    QLabel *label_4;
    QPushButton *backButton;
    QPushButton *genPassButton;
    QPushButton *storePassButton;

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
        passwordText = new QTextEdit(storePassword);
        passwordText->setObjectName("passwordText");
        passwordText->setGeometry(QRect(20, 200, 760, 70));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Bahnschrift Light")});
        font1.setPointSize(12);
        passwordText->setFont(font1);
        passIdText = new QTextEdit(storePassword);
        passIdText->setObjectName("passIdText");
        passIdText->setGeometry(QRect(20, 60, 371, 71));
        passIdText->setFont(font1);
        userText = new QTextEdit(storePassword);
        userText->setObjectName("userText");
        userText->setGeometry(QRect(410, 60, 371, 71));
        userText->setFont(font1);
        label_3 = new QLabel(storePassword);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(340, 170, 111, 20));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        thoughtText = new QTextEdit(storePassword);
        thoughtText->setObjectName("thoughtText");
        thoughtText->setGeometry(QRect(20, 330, 760, 131));
        thoughtText->setFont(font1);
        label_4 = new QLabel(storePassword);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(330, 300, 131, 20));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        backButton = new QPushButton(storePassword);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(20, 500, 121, 81));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Bahnschrift Light")});
        font2.setPointSize(19);
        backButton->setFont(font2);
        genPassButton = new QPushButton(storePassword);
        genPassButton->setObjectName("genPassButton");
        genPassButton->setGeometry(QRect(150, 500, 311, 81));
        genPassButton->setFont(font2);
        storePassButton = new QPushButton(storePassword);
        storePassButton->setObjectName("storePassButton");
        storePassButton->setGeometry(QRect(470, 500, 311, 81));
        storePassButton->setFont(font2);

        retranslateUi(storePassword);

        QMetaObject::connectSlotsByName(storePassword);
    } // setupUi

    void retranslateUi(QDialog *storePassword)
    {
        storePassword->setWindowTitle(QCoreApplication::translate("storePassword", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("storePassword", "Password ID:", nullptr));
        label_2->setText(QCoreApplication::translate("storePassword", "Username: ", nullptr));
        passwordText->setHtml(QCoreApplication::translate("storePassword", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Bahnschrift Light'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        passIdText->setHtml(QCoreApplication::translate("storePassword", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Bahnschrift Light'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Segoe UI'; font-size:9pt;\"><br /></p></body></html>", nullptr));
        userText->setHtml(QCoreApplication::translate("storePassword", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Bahnschrift Light'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Segoe UI'; font-size:9pt;\"><br /></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("storePassword", "Password:", nullptr));
        thoughtText->setHtml(QCoreApplication::translate("storePassword", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Bahnschrift Light'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Segoe UI'; font-size:9pt;\"><br /></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("storePassword", "Thought Bank:", nullptr));
        backButton->setText(QCoreApplication::translate("storePassword", "Back", nullptr));
        genPassButton->setText(QCoreApplication::translate("storePassword", "Password Generator", nullptr));
        storePassButton->setText(QCoreApplication::translate("storePassword", "Save New Password", nullptr));
    } // retranslateUi

};

namespace Ui {
    class storePassword: public Ui_storePassword {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STOREPASSWORD_H
