/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *login;
    QLineEdit *passwordLoginEntry;
    QLabel *label;
    QPushButton *loginButton;
    QLabel *loginErrorLabel;
    QWidget *createPass;
    QLabel *label_2;
    QLineEdit *createPassEntry1;
    QLabel *label_3;
    QLineEdit *createPassEntry2;
    QPushButton *createPassSubmitButton;
    QLabel *creationError;
    QLabel *label_4;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1000, 621);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        login = new QWidget(centralwidget);
        login->setObjectName("login");
        login->setGeometry(QRect(0, 0, 1001, 291));
        passwordLoginEntry = new QLineEdit(login);
        passwordLoginEntry->setObjectName("passwordLoginEntry");
        passwordLoginEntry->setGeometry(QRect(110, 110, 761, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("Bahnschrift Light")});
        font.setPointSize(20);
        passwordLoginEntry->setFont(font);
        passwordLoginEntry->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label = new QLabel(login);
        label->setObjectName("label");
        label->setGeometry(QRect(380, 50, 231, 31));
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        loginButton = new QPushButton(login);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(400, 200, 181, 51));
        loginButton->setFont(font);
        loginErrorLabel = new QLabel(login);
        loginErrorLabel->setObjectName("loginErrorLabel");
        loginErrorLabel->setGeometry(QRect(250, 20, 481, 20));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        loginErrorLabel->setPalette(palette);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Bahnschrift Light")});
        font1.setPointSize(13);
        loginErrorLabel->setFont(font1);
        loginErrorLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        createPass = new QWidget(centralwidget);
        createPass->setObjectName("createPass");
        createPass->setGeometry(QRect(0, 240, 1001, 381));
        label_2 = new QLabel(createPass);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(380, 70, 231, 31));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        createPassEntry1 = new QLineEdit(createPass);
        createPassEntry1->setObjectName("createPassEntry1");
        createPassEntry1->setGeometry(QRect(110, 110, 761, 61));
        createPassEntry1->setFont(font);
        createPassEntry1->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_3 = new QLabel(createPass);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(380, 180, 231, 31));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        createPassEntry2 = new QLineEdit(createPass);
        createPassEntry2->setObjectName("createPassEntry2");
        createPassEntry2->setGeometry(QRect(110, 220, 761, 61));
        createPassEntry2->setFont(font);
        createPassEntry2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        createPassSubmitButton = new QPushButton(createPass);
        createPassSubmitButton->setObjectName("createPassSubmitButton");
        createPassSubmitButton->setGeometry(QRect(400, 290, 181, 51));
        createPassSubmitButton->setFont(font);
        creationError = new QLabel(createPass);
        creationError->setObjectName("creationError");
        creationError->setGeometry(QRect(250, 350, 481, 20));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        creationError->setPalette(palette1);
        creationError->setFont(font1);
        creationError->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_4 = new QLabel(createPass);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(210, 0, 571, 51));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Bahnschrift Light")});
        font2.setPointSize(15);
        label_4->setFont(font2);
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_4->setWordWrap(true);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        passwordLoginEntry->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Enter Password:", nullptr));
        loginButton->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        loginErrorLabel->setText(QCoreApplication::translate("MainWindow", "ERROR", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Create Password:", nullptr));
        createPassEntry1->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "Enter Again:", nullptr));
        createPassEntry2->setText(QString());
        createPassSubmitButton->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        creationError->setText(QCoreApplication::translate("MainWindow", "ERROR", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "WARNING: Remember this password. There is no way to reset the password unless you're logged into the application.", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
