// storepassword.cpp
#include "storepassword.h"
#include "ui_storepassword.h"

storePassword::storePassword(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::storePassword)
{
    ui->setupUi(this);
}

storePassword::~storePassword()
{
    delete ui;
}

void storePassword::on_backButton_clicked()
{
    this->hide();
    emit emitBackClicked();
    ui->passIdText->clear();
    ui->passwordText->clear();
    ui->userText->clear();
    ui->thoughtText->clear();
    this->accept();
}

void storePassword::on_genPassButton_clicked()
{
    emit requestGenPassword();
}
