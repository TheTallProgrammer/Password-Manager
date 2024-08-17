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
