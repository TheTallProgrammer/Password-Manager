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
#include "editpassworddata.h"




// For this, it'll need the password data from the entry in the table passed into this object instance when the edit button is pressed (since it's already decrypted). It'll fill the fields, the user will do what they want. If they hit back, then the instance is just deleted and nothing is returned. If they hit save, they return or emit the new text field data back to the table entry they clicked to edit, and it overwrtites the existing data in that entry with the new data (assuming they changed something, if they just hit save and they didn't change anything, then it would just be the same since the passed in data fills the text boxes anyway)

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

editPasswordData::~editPasswordData()
{
    delete ui;
}



void editPasswordData::on_backButton_clicked()
{
    this->deleteLater();
}


void  editPasswordData::on_saveButton_clicked()
{
    // Collect the new data
    QString newPassId = ui->passwordIdEdit->toPlainText();
    QString newPassword = ui->passwordEdit->toPlainText();
    QString newUsername = ui->usernameEdit->toPlainText();
    QString newThoughts = ui->thoughtsEdit->toPlainText();
    QString newDateStored = QDate::currentDate().toString(Qt::ISODate);

    // Emit the signal to notify that the data needs to be overwritten
    emit overwriteData(newPassId, newDateStored, newPassword, newUsername, newThoughts);

    // Close the dialog
    this->close();
}



