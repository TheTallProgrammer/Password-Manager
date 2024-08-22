#include "passwordmanagementbuttons.h"
#include "ui_passwordmanagementbuttons.h"
#include "passwordgenerator.h"
#include "resetpassword.h"
#include "storepassword.h"
#include "mainwindow.h"  // Include MainWindow to access its methods
#include "retrievepassword.h"
#include <QCloseEvent>

// =============================
// Constructor & Destructor
// =============================
passwordManagementButtons::passwordManagementButtons(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::passwordManagementButtons)
{
    ui->setupUi(this);
}

passwordManagementButtons::~passwordManagementButtons()
{
    if (myPassGen) {
        disconnect(myPassGen.get(), nullptr, this, nullptr);  // Ensure signals are disconnected
    }
    delete ui;
}

void passwordManagementButtons::closeEvent(QCloseEvent *event)
{
    QCoreApplication::quit();  // Quit the entire application
    event->accept();  // Accept the event, allowing the window to close
}

// =======================
// Slot Implementations
// =======================
void passwordManagementButtons::on_genPass_clicked()
{
    if (!myPassGen) {
        myPassGen = std::make_unique<PasswordGenerator>(this);  // Instantiate PasswordGenerator if not already done
    }
    myPassGen->show();  // Display the password generator
}

void passwordManagementButtons::on_resetLoginButton_clicked()
{
    if (!resetPass) {
        resetPass = std::make_unique<resetPassword>(this);  // Instantiate resetPassword if not already done

        // Connect resetPassword's passwordUpdated signal to MainWindow's updatePassword slot
        MainWindow* mainWindow = qobject_cast<MainWindow*>(parentWidget());
        if (mainWindow) {
            bool connection = connect(resetPass.get(), &resetPassword::passwordUpdated, mainWindow, &MainWindow::updatePassword);
            qDebug() << (connection ? "Connected resetPassword::passwordUpdated to MainWindow::updatePassword."
                                    : "Failed to connect resetPassword::passwordUpdated to MainWindow::updatePassword.");
        } else {
            qDebug() << "Failed to cast parentWidget to MainWindow.";
        }

        // Connect resetPassword's resetCanceled signal to onResetCanceled slot
        connect(resetPass.get(), &resetPassword::resetCanceled, this, &passwordManagementButtons::onResetCanceled);
    }

    this->hide();  // Hide this dialog when the reset dialog is active
    resetPass->exec();  // Block until the reset dialog is closed
    this->show();  // Show this dialog again after reset
}

void passwordManagementButtons::onResetCanceled()
{
    this->show();  // Show the main dialog when reset is canceled
}

void passwordManagementButtons::on_logoutButton_clicked()
{
    QCoreApplication::quit();  // Quit the application
}

void passwordManagementButtons::on_storePass_clicked()
{
    if (!storePass) {
        storePass = std::make_unique<storePassword>(this);  // Instantiate storePassword if not already done

        // Connect storePassword's emitBackClicked signal to handleBackStorePassword slot
        connect(storePass.get(), &storePassword::emitBackClicked, this, &passwordManagementButtons::handleBackStorePassword);

        // Connect storePassword's requestGenPassword signal to handleRequestGenPassword slot
        connect(storePass.get(), &storePassword::requestGenPassword, this, &passwordManagementButtons::handleRequestGenPassword);
    }
    this->hide();  // Hide the main dialog when storePassword is shown
    storePass->show();  // Display the storePassword dialog
}

void passwordManagementButtons::handleBackStorePassword()
{
    this->show();  // Show the main dialog when back is clicked in storePassword
}

void passwordManagementButtons::handleRequestGenPassword()
{
    if (!myPassGen) {
        myPassGen = std::make_unique<PasswordGenerator>(this);  // Instantiate PasswordGenerator if not already done
    }
    if (!myPassGen->isVisible()) {
        myPassGen->show();  // Display the password generator if not already visible
    }
}

void passwordManagementButtons::on_retrievePass_clicked()
{
    if (retrievePass) {
        // If an instance already exists, just show it
        retrievePass->show();
        this->hide(); // Hide the main dialog
    } else {
        // Create a new instance of retrievePassword
        retrievePass = new retrievePassword(this); // Use QPointer, no need for std::unique_ptr
        connect(retrievePass, &retrievePassword::emitBackClicked, this, &passwordManagementButtons::handleBackRetrievePassword);

        retrievePass->show();
        this->hide(); // Hide the main dialog when retrievePassword is shown
    }
}

void passwordManagementButtons::handleBackRetrievePassword()
{
    this->show();  // Show the main dialog when back is clicked in retrievePassword

    if (retrievePass) {
        retrievePass->deleteLater(); // Ensure the instance is properly deleted
        retrievePass = nullptr; // Reset the QPointer
    }
}

void passwordManagementButtons::on_deleteAllButton_clicked()
{
    QString dirPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/PasswordManager";
    QDir dir(dirPath);

    // Confirmation dialog
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Delete Confirmation", "Are you certain you wish to delete all stored password data? This action is irreversible, and all saved passwords will be permanently removed.",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        if (dir.exists()) {
            if (dir.removeRecursively()) {
                qDebug() << "All data deleted successfully.";
            } else {
                qDebug() << "Failed to delete the folder.";
            }
        } else {
            qDebug() << "Folder does not exist.";
        }
    } else {
        qDebug() << "Deletion canceled by the user.";
    }
}


