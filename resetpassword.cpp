#include "resetpassword.h"
#include "ui_resetpassword.h"
#include <QDebug>  // Include for debugging

// =========================
// Constructor & Destructor
// =========================
resetPassword::resetPassword(QWidget *parent)
    : QDialog(parent), ui(new Ui::resetPassword)
{
    ui->setupUi(this);

    QPalette palette_loginErr = ui->errorLabel->palette();
    palette_loginErr.setColor(QPalette::WindowText, Qt::red);  // Set the error label text color to red
    ui->errorLabel->setPalette(palette_loginErr);
    ui->errorLabel->hide();  // Hide the error label initially
}

resetPassword::~resetPassword()
{
    delete ui;
}

// ==================
// Slot Implementations
// ==================

// Handles the cancel button click event
void resetPassword::on_cancelButton_clicked()
{
    qDebug() << "Cancel button clicked, emitting resetCanceled signal.";
    emit resetCanceled();  // Emit the signal before clearing the entries
    ui->passEntryOne->clear();  // Clear the first password entry
    ui->passEntryTwo->clear();  // Clear the second password entry
    this->reject();  // Close the dialog using reject
}

// Handles the confirm button click event
void resetPassword::on_confirmButton_clicked()
{
    QString passOne = ui->passEntryOne->text();
    QString passTwo = ui->passEntryTwo->text();

    if (passOne.length() < 8) {
        ui->errorLabel->setText("Password Too Short (8 characters or more)");
        ui->errorLabel->show();  // Show the error label with the appropriate message
    }
    else if (passOne != passTwo) {
        ui->errorLabel->setText("Passwords Don't Match");
        ui->errorLabel->show();  // Show the error label with the appropriate message
    } else {
        qDebug() << "Passwords match, emitting passwordUpdated signal.";
        emit passwordUpdated(passOne);  // Emit the new password if validation passes
        ui->passEntryOne->clear();  // Clear the first password entry
        ui->passEntryTwo->clear();  // Clear the second password entry
        this->accept();  // Close the dialog using accept
    }
}
