/********************************************************************************
** Form generated from reading UI file 'passwordgenerator.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSWORDGENERATOR_H
#define UI_PASSWORDGENERATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PasswordGenerator
{
public:
    QLineEdit *PassLength;
    QLabel *PassLengthLabel;
    QLineEdit *PassComp;
    QLabel *PassCompLabel;
    QPushButton *GenPass;
    QSlider *PassLengthSlider;
    QSlider *PassCompSlider;
    QLineEdit *GeneratedPassLabel;
    QPushButton *CopyButton;
    QWidget *excludeChar;
    QLabel *label;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QLabel *label_6;
    QCheckBox *checkBox_6;
    QLabel *label_7;
    QCheckBox *checkBox_7;
    QLabel *label_8;
    QCheckBox *checkBox_8;
    QLabel *label_9;
    QLabel *label_10;
    QCheckBox *checkBox_9;
    QCheckBox *checkBox_11;
    QLabel *label_12;
    QLabel *label_13;
    QCheckBox *checkBox_12;
    QCheckBox *checkBox_13;
    QLabel *label_14;
    QLabel *label_15;
    QCheckBox *checkBox_14;
    QLabel *label_16;
    QCheckBox *checkBox_15;
    QCheckBox *checkBox_16;
    QLabel *label_17;
    QLabel *label_18;
    QCheckBox *checkBox_17;
    QLabel *label_19;
    QCheckBox *checkBox_18;
    QLabel *label_20;
    QCheckBox *checkBox_19;
    QLabel *label_21;
    QCheckBox *checkBox_10;
    QCheckBox *checkBox_1;
    QLabel *label_22;
    QCheckBox *checkBox_20;
    QLabel *label_23;
    QCheckBox *checkBox_21;
    QCheckBox *checkBox_22;
    QLabel *label_24;
    QLabel *label_25;
    QCheckBox *checkBox_23;
    QLabel *label_26;
    QCheckBox *checkBox_24;
    QLabel *label_27;
    QCheckBox *checkBox_25;
    QLabel *label_28;
    QCheckBox *checkBox_26;
    QLabel *label_29;
    QCheckBox *checkBox_27;
    QLabel *label_30;
    QCheckBox *checkBox_28;
    QPushButton *exitButton;

    void setupUi(QDialog *PasswordGenerator)
    {
        if (PasswordGenerator->objectName().isEmpty())
            PasswordGenerator->setObjectName("PasswordGenerator");
        PasswordGenerator->resize(800, 333);
        PassLength = new QLineEdit(PasswordGenerator);
        PassLength->setObjectName("PassLength");
        PassLength->setGeometry(QRect(60, 30, 150, 75));
        QFont font;
        font.setFamilies({QString::fromUtf8("Yu Gothic Medium")});
        font.setPointSize(20);
        font.setKerning(false);
        PassLength->setFont(font);
        PassLength->setAlignment(Qt::AlignmentFlag::AlignCenter);
        PassLength->setReadOnly(true);
        PassLengthLabel = new QLabel(PasswordGenerator);
        PassLengthLabel->setObjectName("PassLengthLabel");
        PassLengthLabel->setGeometry(QRect(70, 10, 131, 16));
        PassComp = new QLineEdit(PasswordGenerator);
        PassComp->setObjectName("PassComp");
        PassComp->setGeometry(QRect(280, 30, 150, 75));
        PassComp->setFont(font);
        PassComp->setAlignment(Qt::AlignmentFlag::AlignCenter);
        PassComp->setReadOnly(true);
        PassCompLabel = new QLabel(PasswordGenerator);
        PassCompLabel->setObjectName("PassCompLabel");
        PassCompLabel->setGeometry(QRect(280, 10, 151, 20));
        GenPass = new QPushButton(PasswordGenerator);
        GenPass->setObjectName("GenPass");
        GenPass->setGeometry(QRect(490, 30, 261, 75));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Yu Gothic Medium")});
        font1.setPointSize(20);
        GenPass->setFont(font1);
        PassLengthSlider = new QSlider(PasswordGenerator);
        PassLengthSlider->setObjectName("PassLengthSlider");
        PassLengthSlider->setGeometry(QRect(70, 110, 131, 16));
        PassLengthSlider->setMinimum(1);
        PassLengthSlider->setMaximum(32);
        PassLengthSlider->setOrientation(Qt::Orientation::Horizontal);
        PassCompSlider = new QSlider(PasswordGenerator);
        PassCompSlider->setObjectName("PassCompSlider");
        PassCompSlider->setGeometry(QRect(290, 110, 131, 16));
        PassCompSlider->setMinimum(1);
        PassCompSlider->setMaximum(3);
        PassCompSlider->setPageStep(10);
        PassCompSlider->setOrientation(Qt::Orientation::Horizontal);
        GeneratedPassLabel = new QLineEdit(PasswordGenerator);
        GeneratedPassLabel->setObjectName("GeneratedPassLabel");
        GeneratedPassLabel->setGeometry(QRect(60, 220, 691, 51));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Bahnschrift Light")});
        font2.setPointSize(14);
        GeneratedPassLabel->setFont(font2);
        GeneratedPassLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        GeneratedPassLabel->setReadOnly(true);
        CopyButton = new QPushButton(PasswordGenerator);
        CopyButton->setObjectName("CopyButton");
        CopyButton->setGeometry(QRect(250, 280, 141, 41));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Bahnschrift Light")});
        font3.setPointSize(13);
        CopyButton->setFont(font3);
        excludeChar = new QWidget(PasswordGenerator);
        excludeChar->setObjectName("excludeChar");
        excludeChar->setGeometry(QRect(60, 130, 691, 81));
        QFont font4;
        font4.setPointSize(12);
        excludeChar->setFont(font4);
        label = new QLabel(excludeChar);
        label->setObjectName("label");
        label->setGeometry(QRect(270, 0, 141, 16));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Yu Gothic Medium")});
        font5.setPointSize(12);
        font5.setBold(true);
        label->setFont(font5);
        checkBox_2 = new QCheckBox(excludeChar);
        checkBox_2->setObjectName("checkBox_2");
        checkBox_2->setGeometry(QRect(80, 20, 16, 22));
        checkBox_2->setText(QString::fromUtf8("&"));
        checkBox_3 = new QCheckBox(excludeChar);
        checkBox_3->setObjectName("checkBox_3");
        checkBox_3->setGeometry(QRect(150, 20, 16, 22));
        checkBox_3->setText(QString::fromUtf8("&"));
        label_2 = new QLabel(excludeChar);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 20, 16, 16));
        label_3 = new QLabel(excludeChar);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(100, 20, 16, 16));
        label_4 = new QLabel(excludeChar);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(170, 10, 16, 31));
        label_5 = new QLabel(excludeChar);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(240, 20, 16, 16));
        checkBox_4 = new QCheckBox(excludeChar);
        checkBox_4->setObjectName("checkBox_4");
        checkBox_4->setGeometry(QRect(220, 20, 16, 22));
        checkBox_4->setText(QString::fromUtf8("&"));
        checkBox_5 = new QCheckBox(excludeChar);
        checkBox_5->setObjectName("checkBox_5");
        checkBox_5->setGeometry(QRect(290, 20, 16, 22));
        checkBox_5->setText(QString::fromUtf8("&"));
        label_6 = new QLabel(excludeChar);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(310, 10, 16, 31));
        checkBox_6 = new QCheckBox(excludeChar);
        checkBox_6->setObjectName("checkBox_6");
        checkBox_6->setGeometry(QRect(360, 20, 16, 22));
        label_7 = new QLabel(excludeChar);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(380, 10, 16, 31));
        checkBox_7 = new QCheckBox(excludeChar);
        checkBox_7->setObjectName("checkBox_7");
        checkBox_7->setGeometry(QRect(420, 20, 16, 22));
        label_8 = new QLabel(excludeChar);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(440, 10, 16, 31));
        checkBox_8 = new QCheckBox(excludeChar);
        checkBox_8->setObjectName("checkBox_8");
        checkBox_8->setGeometry(QRect(490, 20, 16, 22));
        checkBox_8->setText(QString::fromUtf8("&"));
        label_9 = new QLabel(excludeChar);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(510, 10, 16, 31));
        label_10 = new QLabel(excludeChar);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(570, 10, 16, 31));
        checkBox_9 = new QCheckBox(excludeChar);
        checkBox_9->setObjectName("checkBox_9");
        checkBox_9->setGeometry(QRect(550, 20, 16, 22));
        checkBox_9->setText(QString::fromUtf8("&"));
        checkBox_11 = new QCheckBox(excludeChar);
        checkBox_11->setObjectName("checkBox_11");
        checkBox_11->setGeometry(QRect(10, 40, 16, 22));
        checkBox_11->setText(QString::fromUtf8("&"));
        label_12 = new QLabel(excludeChar);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(30, 30, 16, 31));
        label_13 = new QLabel(excludeChar);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(100, 30, 16, 31));
        checkBox_12 = new QCheckBox(excludeChar);
        checkBox_12->setObjectName("checkBox_12");
        checkBox_12->setGeometry(QRect(80, 40, 16, 22));
        checkBox_12->setText(QString::fromUtf8("&"));
        checkBox_13 = new QCheckBox(excludeChar);
        checkBox_13->setObjectName("checkBox_13");
        checkBox_13->setGeometry(QRect(150, 40, 16, 22));
        checkBox_13->setText(QString::fromUtf8("&"));
        label_14 = new QLabel(excludeChar);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(170, 30, 16, 31));
        label_15 = new QLabel(excludeChar);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(240, 30, 16, 31));
        checkBox_14 = new QCheckBox(excludeChar);
        checkBox_14->setObjectName("checkBox_14");
        checkBox_14->setGeometry(QRect(220, 40, 16, 22));
        checkBox_14->setText(QString::fromUtf8("&"));
        label_16 = new QLabel(excludeChar);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(310, 30, 21, 51));
        checkBox_15 = new QCheckBox(excludeChar);
        checkBox_15->setObjectName("checkBox_15");
        checkBox_15->setGeometry(QRect(290, 40, 16, 22));
        checkBox_15->setText(QString::fromUtf8("&"));
        checkBox_16 = new QCheckBox(excludeChar);
        checkBox_16->setObjectName("checkBox_16");
        checkBox_16->setGeometry(QRect(360, 40, 16, 22));
        checkBox_16->setText(QString::fromUtf8("&"));
        label_17 = new QLabel(excludeChar);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(380, 30, 16, 31));
        label_18 = new QLabel(excludeChar);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(440, 30, 16, 31));
        checkBox_17 = new QCheckBox(excludeChar);
        checkBox_17->setObjectName("checkBox_17");
        checkBox_17->setGeometry(QRect(420, 40, 16, 22));
        checkBox_17->setText(QString::fromUtf8("&"));
        label_19 = new QLabel(excludeChar);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(510, 30, 21, 31));
        checkBox_18 = new QCheckBox(excludeChar);
        checkBox_18->setObjectName("checkBox_18");
        checkBox_18->setGeometry(QRect(490, 40, 16, 22));
        checkBox_18->setText(QString::fromUtf8("&"));
        label_20 = new QLabel(excludeChar);
        label_20->setObjectName("label_20");
        label_20->setGeometry(QRect(570, 40, 16, 21));
        QFont font6;
        font6.setFamilies({QString::fromUtf8("Yu Gothic Medium")});
        font6.setPointSize(12);
        font6.setBold(false);
        label_20->setFont(font6);
        checkBox_19 = new QCheckBox(excludeChar);
        checkBox_19->setObjectName("checkBox_19");
        checkBox_19->setGeometry(QRect(550, 40, 16, 22));
        checkBox_19->setText(QString::fromUtf8("&"));
        label_21 = new QLabel(excludeChar);
        label_21->setObjectName("label_21");
        label_21->setGeometry(QRect(630, 20, 16, 41));
        QFont font7;
        font7.setFamilies({QString::fromUtf8("Yu Gothic Medium")});
        font7.setPointSize(23);
        font7.setBold(false);
        font7.setItalic(false);
        font7.setKerning(false);
        label_21->setFont(font7);
        checkBox_10 = new QCheckBox(excludeChar);
        checkBox_10->setObjectName("checkBox_10");
        checkBox_10->setGeometry(QRect(610, 20, 16, 22));
        checkBox_10->setText(QString::fromUtf8("&"));
        checkBox_1 = new QCheckBox(excludeChar);
        checkBox_1->setObjectName("checkBox_1");
        checkBox_1->setGeometry(QRect(10, 20, 16, 22));
        checkBox_1->setText(QString::fromUtf8("&"));
        label_22 = new QLabel(excludeChar);
        label_22->setObjectName("label_22");
        label_22->setGeometry(QRect(630, 40, 16, 21));
        label_22->setFont(font6);
        checkBox_20 = new QCheckBox(excludeChar);
        checkBox_20->setObjectName("checkBox_20");
        checkBox_20->setGeometry(QRect(610, 40, 16, 22));
        checkBox_20->setText(QString::fromUtf8("&"));
        label_23 = new QLabel(excludeChar);
        label_23->setObjectName("label_23");
        label_23->setGeometry(QRect(100, 50, 16, 31));
        checkBox_21 = new QCheckBox(excludeChar);
        checkBox_21->setObjectName("checkBox_21");
        checkBox_21->setGeometry(QRect(80, 60, 16, 22));
        checkBox_21->setText(QString::fromUtf8("&"));
        checkBox_22 = new QCheckBox(excludeChar);
        checkBox_22->setObjectName("checkBox_22");
        checkBox_22->setGeometry(QRect(150, 60, 16, 22));
        checkBox_22->setText(QString::fromUtf8("&"));
        label_24 = new QLabel(excludeChar);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(170, 50, 16, 31));
        label_25 = new QLabel(excludeChar);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(240, 50, 16, 31));
        checkBox_23 = new QCheckBox(excludeChar);
        checkBox_23->setObjectName("checkBox_23");
        checkBox_23->setGeometry(QRect(220, 60, 16, 22));
        checkBox_23->setText(QString::fromUtf8("&"));
        label_26 = new QLabel(excludeChar);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(310, 50, 16, 31));
        checkBox_24 = new QCheckBox(excludeChar);
        checkBox_24->setObjectName("checkBox_24");
        checkBox_24->setGeometry(QRect(290, 60, 16, 22));
        checkBox_24->setText(QString::fromUtf8("&"));
        label_27 = new QLabel(excludeChar);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(380, 50, 16, 31));
        checkBox_25 = new QCheckBox(excludeChar);
        checkBox_25->setObjectName("checkBox_25");
        checkBox_25->setGeometry(QRect(360, 60, 16, 22));
        checkBox_25->setText(QString::fromUtf8("&"));
        label_28 = new QLabel(excludeChar);
        label_28->setObjectName("label_28");
        label_28->setGeometry(QRect(440, 50, 16, 31));
        checkBox_26 = new QCheckBox(excludeChar);
        checkBox_26->setObjectName("checkBox_26");
        checkBox_26->setGeometry(QRect(420, 60, 16, 22));
        checkBox_26->setText(QString::fromUtf8("&"));
        label_29 = new QLabel(excludeChar);
        label_29->setObjectName("label_29");
        label_29->setGeometry(QRect(510, 50, 16, 31));
        checkBox_27 = new QCheckBox(excludeChar);
        checkBox_27->setObjectName("checkBox_27");
        checkBox_27->setGeometry(QRect(490, 60, 16, 22));
        checkBox_27->setText(QString::fromUtf8("&"));
        label_30 = new QLabel(excludeChar);
        label_30->setObjectName("label_30");
        label_30->setGeometry(QRect(570, 50, 16, 31));
        checkBox_28 = new QCheckBox(excludeChar);
        checkBox_28->setObjectName("checkBox_28");
        checkBox_28->setGeometry(QRect(550, 60, 16, 22));
        checkBox_28->setText(QString::fromUtf8("&"));
        exitButton = new QPushButton(PasswordGenerator);
        exitButton->setObjectName("exitButton");
        exitButton->setGeometry(QRect(430, 280, 141, 41));
        exitButton->setFont(font3);

        retranslateUi(PasswordGenerator);

        QMetaObject::connectSlotsByName(PasswordGenerator);
    } // setupUi

    void retranslateUi(QDialog *PasswordGenerator)
    {
        PasswordGenerator->setWindowTitle(QCoreApplication::translate("PasswordGenerator", "Dialog", nullptr));
        PassLength->setText(QString());
        PassLengthLabel->setText(QCoreApplication::translate("PasswordGenerator", "Password Length: (1-32)", nullptr));
        PassComp->setText(QString());
        PassCompLabel->setText(QCoreApplication::translate("PasswordGenerator", "Password Complexity: (1-3)", nullptr));
        GenPass->setText(QCoreApplication::translate("PasswordGenerator", "Generate Password", nullptr));
        GeneratedPassLabel->setText(QString());
        CopyButton->setText(QCoreApplication::translate("PasswordGenerator", "Copy", nullptr));
        label->setText(QCoreApplication::translate("PasswordGenerator", "Exclude Symbols:", nullptr));
        label_2->setText(QCoreApplication::translate("PasswordGenerator", "&", nullptr));
        label_3->setText(QCoreApplication::translate("PasswordGenerator", "@", nullptr));
        label_4->setText(QCoreApplication::translate("PasswordGenerator", "{ }", nullptr));
        label_5->setText(QCoreApplication::translate("PasswordGenerator", "#", nullptr));
        label_6->setText(QCoreApplication::translate("PasswordGenerator", "[ ]", nullptr));
        checkBox_6->setText(QCoreApplication::translate("PasswordGenerator", "=", nullptr));
        label_7->setText(QCoreApplication::translate("PasswordGenerator", "=", nullptr));
        checkBox_7->setText(QCoreApplication::translate("PasswordGenerator", "+", nullptr));
        label_8->setText(QCoreApplication::translate("PasswordGenerator", "( )", nullptr));
        label_9->setText(QCoreApplication::translate("PasswordGenerator", "-", nullptr));
        label_10->setText(QCoreApplication::translate("PasswordGenerator", "?", nullptr));
        label_12->setText(QCoreApplication::translate("PasswordGenerator", "\\", nullptr));
        label_13->setText(QCoreApplication::translate("PasswordGenerator", "/", nullptr));
        label_14->setText(QCoreApplication::translate("PasswordGenerator", "|", nullptr));
        label_15->setText(QCoreApplication::translate("PasswordGenerator", "*", nullptr));
        label_16->setText(QCoreApplication::translate("PasswordGenerator", "\"\"", nullptr));
        label_17->setText(QCoreApplication::translate("PasswordGenerator", ":", nullptr));
        label_18->setText(QCoreApplication::translate("PasswordGenerator", ";", nullptr));
        label_19->setText(QCoreApplication::translate("PasswordGenerator", "<>", nullptr));
        label_20->setText(QCoreApplication::translate("PasswordGenerator", "~", nullptr));
        label_21->setText(QCoreApplication::translate("PasswordGenerator", "`", nullptr));
        label_22->setText(QCoreApplication::translate("PasswordGenerator", "$", nullptr));
        label_23->setText(QCoreApplication::translate("PasswordGenerator", "!", nullptr));
        label_24->setText(QCoreApplication::translate("PasswordGenerator", "%", nullptr));
        label_25->setText(QCoreApplication::translate("PasswordGenerator", "^", nullptr));
        label_26->setText(QCoreApplication::translate("PasswordGenerator", "_", nullptr));
        label_27->setText(QCoreApplication::translate("PasswordGenerator", "+", nullptr));
        label_28->setText(QCoreApplication::translate("PasswordGenerator", "' '", nullptr));
        label_29->setText(QCoreApplication::translate("PasswordGenerator", ",", nullptr));
        label_30->setText(QCoreApplication::translate("PasswordGenerator", ".", nullptr));
        exitButton->setText(QCoreApplication::translate("PasswordGenerator", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PasswordGenerator: public Ui_PasswordGenerator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORDGENERATOR_H
