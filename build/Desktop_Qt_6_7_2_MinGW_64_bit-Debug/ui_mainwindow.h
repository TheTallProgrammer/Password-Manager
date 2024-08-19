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
    QLineEdit *passwordLoginEntry_4;
    QLabel *label_8;
    QPushButton *loginButton_4;
    QLabel *loginErrorLabel_4;
    QLineEdit *cipherText;
    QLabel *label_2;
    QWidget *createPass;
    QLabel *label_10;
    QLineEdit *createPassEntry1_2;
    QLabel *label_11;
    QLineEdit *createPassEntry2_2;
    QPushButton *createPassSubmitButton_2;
    QLabel *creationError_2;
    QLabel *label_12;
    QLineEdit *emailText_2;
    QLabel *emailLabel_2;
    QLabel *label_13;
    QLineEdit *cipherKeyText_2;
    QPushButton *copyCipherButton_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 611);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        login = new QWidget(centralwidget);
        login->setObjectName("login");
        login->setEnabled(true);
        login->setGeometry(QRect(-90, -10, 1001, 421));
        passwordLoginEntry_4 = new QLineEdit(login);
        passwordLoginEntry_4->setObjectName("passwordLoginEntry_4");
        passwordLoginEntry_4->setGeometry(QRect(110, 110, 761, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("Bahnschrift Light")});
        font.setPointSize(20);
        passwordLoginEntry_4->setFont(font);
        passwordLoginEntry_4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_8 = new QLabel(login);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(370, 60, 231, 31));
        label_8->setFont(font);
        label_8->setAlignment(Qt::AlignmentFlag::AlignCenter);
        loginButton_4 = new QPushButton(login);
        loginButton_4->setObjectName("loginButton_4");
        loginButton_4->setGeometry(QRect(390, 350, 181, 51));
        loginButton_4->setFont(font);
        loginErrorLabel_4 = new QLabel(login);
        loginErrorLabel_4->setObjectName("loginErrorLabel_4");
        loginErrorLabel_4->setGeometry(QRect(240, 20, 481, 20));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        loginErrorLabel_4->setPalette(palette);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Bahnschrift Light")});
        font1.setPointSize(13);
        loginErrorLabel_4->setFont(font1);
        loginErrorLabel_4->setAlignment(Qt::AlignmentFlag::AlignCenter);
        cipherText = new QLineEdit(login);
        cipherText->setObjectName("cipherText");
        cipherText->setGeometry(QRect(112, 260, 761, 61));
        label_2 = new QLabel(login);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(390, 210, 201, 41));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Bahnschrift Light")});
        font2.setPointSize(18);
        label_2->setFont(font2);
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        createPass = new QWidget(centralwidget);
        createPass->setObjectName("createPass");
        createPass->setGeometry(QRect(-90, 0, 1001, 611));
        label_10 = new QLabel(createPass);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(380, 120, 231, 31));
        label_10->setFont(font);
        label_10->setAlignment(Qt::AlignmentFlag::AlignCenter);
        createPassEntry1_2 = new QLineEdit(createPass);
        createPassEntry1_2->setObjectName("createPassEntry1_2");
        createPassEntry1_2->setGeometry(QRect(110, 160, 761, 61));
        createPassEntry1_2->setFont(font);
        createPassEntry1_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_11 = new QLabel(createPass);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(345, 230, 301, 31));
        label_11->setFont(font);
        label_11->setAlignment(Qt::AlignmentFlag::AlignCenter);
        createPassEntry2_2 = new QLineEdit(createPass);
        createPassEntry2_2->setObjectName("createPassEntry2_2");
        createPassEntry2_2->setGeometry(QRect(110, 270, 761, 61));
        createPassEntry2_2->setFont(font);
        createPassEntry2_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        createPassEntry2_2->setReadOnly(false);
        createPassSubmitButton_2 = new QPushButton(createPass);
        createPassSubmitButton_2->setObjectName("createPassSubmitButton_2");
        createPassSubmitButton_2->setGeometry(QRect(390, 530, 201, 51));
        createPassSubmitButton_2->setFont(font);
        creationError_2 = new QLabel(createPass);
        creationError_2->setObjectName("creationError_2");
        creationError_2->setGeometry(QRect(250, 590, 481, 20));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        creationError_2->setPalette(palette1);
        creationError_2->setFont(font1);
        creationError_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_12 = new QLabel(createPass);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(150, 425, 691, 101));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Bahnschrift Light")});
        font3.setPointSize(15);
        label_12->setFont(font3);
        label_12->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label_12->setWordWrap(true);
        emailText_2 = new QLineEdit(createPass);
        emailText_2->setObjectName("emailText_2");
        emailText_2->setGeometry(QRect(110, 50, 761, 61));
        emailText_2->setFont(font);
        emailText_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        emailLabel_2 = new QLabel(createPass);
        emailLabel_2->setObjectName("emailLabel_2");
        emailLabel_2->setGeometry(QRect(410, 0, 161, 41));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Bahnschrift Light")});
        font4.setPointSize(21);
        emailLabel_2->setFont(font4);
        label_13 = new QLabel(createPass);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(430, 340, 131, 31));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Bahnschrift Light")});
        font5.setPointSize(19);
        label_13->setFont(font5);
        label_13->setAlignment(Qt::AlignmentFlag::AlignCenter);
        cipherKeyText_2 = new QLineEdit(createPass);
        cipherKeyText_2->setObjectName("cipherKeyText_2");
        cipherKeyText_2->setGeometry(QRect(230, 380, 521, 41));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Bahnschrift SemiLight")});
        font6.setPointSize(13);
        cipherKeyText_2->setFont(font6);
        cipherKeyText_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        cipherKeyText_2->setReadOnly(true);
        copyCipherButton_2 = new QPushButton(createPass);
        copyCipherButton_2->setObjectName("copyCipherButton_2");
        copyCipherButton_2->setGeometry(QRect(760, 380, 111, 41));
        QFont font7;
        font7.setFamilies({QString::fromUtf8("Bahnschrift Light")});
        font7.setPointSize(17);
        copyCipherButton_2->setFont(font7);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        passwordLoginEntry_4->setText(QString());
        label_8->setText(QCoreApplication::translate("MainWindow", "Enter Password:", nullptr));
        loginButton_4->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        loginErrorLabel_4->setText(QCoreApplication::translate("MainWindow", "ERROR", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Enter Cipher Key:", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Create Password:", nullptr));
        createPassEntry1_2->setText(QString());
        label_11->setText(QCoreApplication::translate("MainWindow", "Enter Password Again:", nullptr));
        createPassEntry2_2->setText(QString());
        createPassSubmitButton_2->setText(QCoreApplication::translate("MainWindow", "Create Account", nullptr));
        creationError_2->setText(QCoreApplication::translate("MainWindow", "ERROR", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "WARNING: This unique cipher key will be used to encrypt/decrypt ALL of your saved data. To ensure extensive security, this program is NOT designed to save the key. It is generated ONCE. Remember this key. It's advised not to save it on the same machine as the manager.", nullptr));
        emailText_2->setText(QString());
        emailLabel_2->setText(QCoreApplication::translate("MainWindow", "Enter Email:", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Cipher Key:", nullptr));
        copyCipherButton_2->setText(QCoreApplication::translate("MainWindow", "Copy", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
