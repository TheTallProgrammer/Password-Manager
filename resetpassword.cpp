#include "resetpassword.h"
#include "ui_resetpassword.h"
#include <QDebug>  // Include for debugging

resetPassword::resetPassword(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::resetPassword)
{
    ui->setupUi(this);

    QPalette palette_loginErr = ui->errorLabel->palette();
    palette_loginErr.setColor(QPalette::WindowText, Qt::red);  // Set to red or any other color
    ui->errorLabel->setPalette(palette_loginErr);
    ui->errorLabel->hide();
}

resetPassword::~resetPassword()
{
    delete ui;
}

void resetPassword::on_cancelButton_clicked()
{
    qDebug() << "Cancel button clicked, emitting resetCanceled signal.";
    emit resetCanceled();  // Emit the signal first
    ui->passEntryOne->clear();
    ui->passEntryTwo->clear();
    this->reject();  // Use reject to close the dialog in response to cancel
}

void resetPassword::on_confirmButton_clicked()
{
    QString passOne = ui->passEntryOne->text();
    QString passTwo = ui->passEntryTwo->text();

    if(passOne.length() < 8){
        ui->errorLabel->setText("Password Too Short (8 characters or more)");
        ui->errorLabel->show();
    }
    else if(passOne != passTwo){
        ui->errorLabel->setText("Passwords Don't Match");
        ui->errorLabel->show();
    } else {
        qDebug() << "Passwords match, emitting passwordUpdated signal.";
        emit passwordUpdated(passOne);  // Emit the new password
        ui->passEntryOne->clear();
        ui->passEntryTwo->clear();
        this->accept();  // Close the dialog
    }
}
