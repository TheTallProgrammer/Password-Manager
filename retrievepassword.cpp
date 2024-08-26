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

// Constructor for the retrievePassword class
retrievePassword::retrievePassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::retrievePassword)
{
    ui->setupUi(this);
    setWindowTitle("Falkenberg's Password Manager");

    // Set up the table widget with 4 columns
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setHorizontalHeaderLabels({"Password ID", "Date", "Copy Password", "Edit", "Delete"});

    // Set the width of each column to equally distribute across the 800 width
    int columnWidth = 154;
    ui->tableWidget->setColumnWidth(0, columnWidth); // Password ID
    ui->tableWidget->setColumnWidth(1, columnWidth); // Date
    ui->tableWidget->setColumnWidth(2, columnWidth); // Copy Password
    ui->tableWidget->setColumnWidth(3, columnWidth); // Edit Button
    ui->tableWidget->setColumnWidth(4, columnWidth); // Delete Button

    loadPasswords();
}

// Destructor
retrievePassword::~retrievePassword()
{
    delete ui;
}


// Load and decrypt all saved passwords
void retrievePassword::loadPasswords()
{
    QString dirPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/PasswordManager";
    QDir dir(dirPath);

    int rowHeight = 50;  // Set desired row height

    // Iterate over each file in the directory
    foreach(QFileInfo item, dir.entryInfoList(QDir::Files)) {
        QString filePath = item.absoluteFilePath();
        QFile file(filePath);

        if (file.open(QIODevice::ReadOnly)) {
            QDataStream in(&file);
            QByteArray encryptedData;
            in >> encryptedData;
            file.close();

            // Decrypt the data using the globalCipherKey from MainWindow
            QByteArray decryptedData = CryptoUtils::decryptData(encryptedData, globalCipherKey);
            QJsonDocument doc = QJsonDocument::fromJson(decryptedData);

            if (!doc.isNull()) {
                QJsonObject json = doc.object();
                QString passId = json["passId"].toString();
                QString dateStored = json["dateStored"].toString();
                QString password = json["password"].toString();
                QString username = json["username"].toString();
                QString thoughts = json["thoughts"].toString();


                // Add a new row for this password entry
                int rowCount = ui->tableWidget->rowCount();
                ui->tableWidget->insertRow(rowCount);

                // Set Password ID and make it read-only
                QTableWidgetItem *idItem = new QTableWidgetItem(passId);
                idItem->setFlags(idItem->flags() & ~Qt::ItemIsEditable);
                ui->tableWidget->setItem(rowCount, 0, idItem);

                // Set Date Stored and make it read-only
                QTableWidgetItem *dateItem = new QTableWidgetItem(dateStored);
                dateItem->setFlags(dateItem->flags() & ~Qt::ItemIsEditable);
                ui->tableWidget->setItem(rowCount, 1, dateItem);

                // Add Copy button
                QPushButton *copyButton = new QPushButton("Copy Password");
                connect(copyButton, &QPushButton::clicked, this, [password]() {
                    QClipboard *clipboard = QApplication::clipboard();
                    clipboard->setText(password);  // Copy the generated password to the clipboard
                });
                ui->tableWidget->setCellWidget(rowCount, 2, copyButton);

                // Add Edit button
                QPushButton *editButton = new QPushButton("Edit");
                connect(editButton, &QPushButton::clicked, this, [this, passId, password, dateStored, username, thoughts, rowCount]() {
                    // Hide the retrievePassword window
                    this->hide();

                    // Create and open the editPasswordData dialog
                    editDialog = new editPasswordData(this, passId, dateStored, password, username, thoughts);

                    // Connect the signal to the slot
                    connect(editDialog, &editPasswordData::overwriteData, this, &retrievePassword::handleOverwriteData);

                    editDialog->exec();  // Open the dialog modally
                    this->show();

                });
                ui->tableWidget->setCellWidget(rowCount, 3, editButton);

                // Add Delete button
                QPushButton *deleteButton = new QPushButton("Delete");
                connect(deleteButton, &QPushButton::clicked, this, [this, passId, rowCount]() {
                    deletePassword(passId, rowCount);
                });
                ui->tableWidget->setCellWidget(rowCount, 4, deleteButton);

                // Set row height
                ui->tableWidget->setRowHeight(rowCount, rowHeight);
            }
        }
    }
}

// Slot to handle the overwrite data signal from editPasswordData
void retrievePassword::handleOverwriteData(const QString &newPassId, const QString &dateStored, const QString &password, const QString &username, const QString &thoughts)
{
    // Handle the update in your retrievePassword class
    saveUpdatedDataToFile(newPassId, newPassId, password, username, thoughts);

    // Optionally reload data
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(0);
    loadPasswords();

    // Show the retrievePassword window again
    this->show();
}

// Function to save the updated data to the file
void retrievePassword::saveUpdatedDataToFile(const QString &oldPassId, const QString &newPassId, const QString &password, const QString &username, const QString &thoughts)
{
    QString dirPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/PasswordManager/";
    QString oldFilePath = dirPath + oldPassId + ".bin";
    QString newFilePath = dirPath + newPassId + ".bin";

    // If the passId has changed, rename the file
    if (oldPassId != newPassId) {
        if (QFile::exists(newFilePath)) {
            qWarning() << "A file with the new passId already exists:" << newFilePath;
            return;
        }
        if (!QFile::rename(oldFilePath, newFilePath)) {
            qWarning() << "Failed to rename the file from" << oldFilePath << "to" << newFilePath;
            return;
        }
    }

    QFile file(newFilePath);
    if (file.open(QIODevice::WriteOnly)) {
        QJsonObject json;
        json["passId"] = newPassId;
        json["password"] = password;
        json["username"] = username;
        json["thoughts"] = thoughts;
        json["dateStored"] = QDate::currentDate().toString(Qt::ISODate);

        QJsonDocument doc(json);
        QByteArray jsonData = doc.toJson();
        QByteArray encryptedData = CryptoUtils::encryptData(jsonData, globalCipherKey);

        QDataStream out(&file);
        out << encryptedData;
        file.close();

        qDebug() << "Password entry updated in file:" << newFilePath;
    } else {
        qWarning() << "Could not open file for writing:" << newFilePath;
    }
}


// Delete password entry
void retrievePassword::deletePassword(const QString &passId, int row)
{
    // Confirmation dialog
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Delete Confirmation", "Are you sure you want to delete this password entry?",
                                  QMessageBox::Yes|QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        // Remove the file
        QString filePath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/PasswordManager/" + passId + ".bin";
        if (QFile::remove(filePath)) {
            // Remove the row from the table
            ui->tableWidget->removeRow(row);
        } else {
            qDebug() << "Failed to delete the file: " << filePath;
        }
    } else {
        qDebug() << "Deletion canceled by the user.";
    }
}

void retrievePassword::on_backButton_clicked()
{
    emit emitBackClicked(); // Emit the signal to inform the parent dialog
    this->close(); // Close the dialog
    deleteLater(); // Safely delete the instance
}
