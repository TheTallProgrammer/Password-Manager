#include "resetpassword.h"
#include "ui_resetpassword.h"

resetPassword::resetPassword(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::resetPassword)
{
    ui->setupUi(this);
}

resetPassword::~resetPassword()
{
    delete ui;
}

void resetPassword::on_cancelButton_clicked()
{
    emit resetCanceled();  // Emit the signal first
    this->reject();  // Use reject to close the dialog in response to cancel
}
