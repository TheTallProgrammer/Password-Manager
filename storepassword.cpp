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
    this->accept();
}

void storePassword::on_genPassButton_clicked()
{
    emit requestGenPassword();  // Emit the signal
}
