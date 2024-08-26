#include "editpassworddata.h"
#include "ui_editpassworddata.h"
#include <QStandardPaths>
#include "retrievePassword.h"
#include "ui_retrievepassword.h"
#include "CryptoUtils.h"
#include "QPushButton"
#include <QFile>
#include <QDir>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTableWidgetItem>
#include <QStandardPaths>
#include "mainwindow.h"  // Include this to access globalCipherKey
#include <QMessageBox>

// ====================
// editPasswordData Constructor
// ====================
editPasswordData::editPasswordData(QWidget *parent, QString passId, QString dateStored, QString password, QString username, QString thoughts)
    : QDialog(parent)
    , ui(new Ui::editPasswordData)
{
    ui->setupUi(this);
    ui->passwordIdEdit->setText(passId);
    ui->passwordEdit->setText(password);
    ui->usernameEdit->setText(username);
    ui->thoughtsEdit->setText(thoughts);
    setWindowTitle("Falkenberg's Password Manager");
}

// ====================
// editPasswordData Destructor
// ====================
editPasswordData::~editPasswordData()
{
    delete ui;
}

// ====================
// Private Slots
// ====================

// Handle back button click
void editPasswordData::on_backButton_clicked()
{
    this->deleteLater();
}

// Handle save button click
void editPasswordData::on_saveButton_clicked()
{
    QString newPassId = ui->passwordIdEdit->toPlainText();  // Collect new password ID
    QString newPassword = ui->passwordEdit->toPlainText();  // Collect new password
    QString newUsername = ui->usernameEdit->toPlainText();  // Collect new username
    QString newThoughts = ui->thoughtsEdit->toPlainText();  // Collect new thoughts
    QString newDateStored = QDate::currentDate().toString(Qt::ISODate);  // Collect new date stored

    emit overwriteData(newPassId, newDateStored, newPassword, newUsername, newThoughts);  // Emit signal to overwrite data

    this->close();  // Close the dialog
}
