#include "passwordmanagementbuttons.h"
#include "ui_passwordmanagementbuttons.h"
#include "passwordgenerator.h"

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
    if(!myPassGen){
        myPassGen = std::make_unique<PasswordGenerator>();
    }
    myPassGen->show();
}



void passwordManagementButtons::on_resetLoginButton_clicked()
{

}

