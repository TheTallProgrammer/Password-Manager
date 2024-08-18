#include "passwordmanagementbuttons.h"
#include "ui_passwordmanagementbuttons.h"
#include "passwordgenerator.h"
#include "resetpassword.h"

passwordManagementButtons::passwordManagementButtons(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::passwordManagementButtons)
{
    ui->setupUi(this);
}

passwordManagementButtons::~passwordManagementButtons()
{
    delete ui;
}

void passwordManagementButtons::on_genPass_clicked()
{
    if (!myPassGen) {
        myPassGen = std::make_unique<PasswordGenerator>();
    }
    myPassGen->show();
}

void passwordManagementButtons::on_resetLoginButton_clicked()
{
    if (!resetPass) {
        resetPass = std::make_unique<resetPassword>(this);  // Set this as the parent
        connect(resetPass.get(), &resetPassword::resetCanceled, this, &passwordManagementButtons::onResetCanceled);
    }
    this->hide();  // Hide this dialog when the reset dialog is active
    resetPass->exec();  // Use exec() to block until the dialog is closed
}

void passwordManagementButtons::onResetCanceled()
{
    this->show();
}

void passwordManagementButtons::on_logoutButton_clicked()
{
    this->deleteLater();
}

