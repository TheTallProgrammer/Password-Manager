#include "passwordmanagementbuttons.h"
#include "ui_passwordmanagementbuttons.h"
#include "passwordgenerator.h"
#include "resetpassword.h"
#include "mainwindow.h"  // Include MainWindow to access its methods
#include <QDebug>

passwordManagementButtons::passwordManagementButtons(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::passwordManagementButtons)
{
    ui->setupUi(this);
}

passwordManagementButtons::~passwordManagementButtons()
{
    if (myPassGen) {
        disconnect(myPassGen.get(), nullptr, this, nullptr);
    }
    delete ui;
}

void passwordManagementButtons::on_genPass_clicked()
{
    if (!myPassGen) {
        myPassGen = std::make_unique<PasswordGenerator>(this);  // Pass 'this' as the parent
    }
    myPassGen->show(); // Use exec() to block until the dialog is closed
}


void passwordManagementButtons::on_resetLoginButton_clicked()
{
    if (!resetPass) {
        resetPass = std::make_unique<resetPassword>(this);  // Set this as the parent

        // Connect the resetPassword signal to MainWindow's updatePassword slot
        MainWindow* mainWindow = qobject_cast<MainWindow*>(parentWidget());
        if (mainWindow) {
            bool connection = connect(resetPass.get(), &resetPassword::passwordUpdated, mainWindow, &MainWindow::updatePassword);
            if (connection) {
                qDebug() << "Connection established between resetPassword::passwordUpdated and MainWindow::updatePassword.";
            } else {
                qDebug() << "Failed to connect resetPassword::passwordUpdated and MainWindow::updatePassword.";
            }
        } else {
            qDebug() << "Failed to cast parentWidget to MainWindow.";
        }

        connect(resetPass.get(), &resetPassword::resetCanceled, this, &passwordManagementButtons::onResetCanceled);
    }

    this->hide();  // Hide this dialog when the reset dialog is active
    resetPass->exec();  // Use exec() to block until the dialog is closed

    this->show();  // Forcefully show this dialog again after reset
}

void passwordManagementButtons::onResetCanceled()
{
    this->show();
}

void passwordManagementButtons::on_logoutButton_clicked()
{
    QCoreApplication::quit();
}
