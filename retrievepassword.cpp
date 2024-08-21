#include "retrievePassword.h"
#include "ui_retrievePassword.h"
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

// Constructor for the retrievePassword class
retrievePassword::retrievePassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::retrievePassword)
{
    ui->setupUi(this);

    // Set up the table widget with 4 columns
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels({"Password ID", "Date", "Edit", "Delete"});

    // Set the width of each column to equally distribute across the 800 width
    int columnWidth = 195;
    ui->tableWidget->setColumnWidth(0, columnWidth); // Password ID
    ui->tableWidget->setColumnWidth(1, columnWidth); // Date
    ui->tableWidget->setColumnWidth(2, columnWidth); // Edit Button
    ui->tableWidget->setColumnWidth(3, columnWidth); // Delete Button

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

    int rowHeight = 30;  // Set desired row height

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
            QByteArray decryptedData = CryptoUtils::decryptData(encryptedData, globalCipherKey, 10);
            QJsonDocument doc = QJsonDocument::fromJson(decryptedData);

            if (!doc.isNull()) {
                QJsonObject json = doc.object();
                QString passId = json["passId"].toString();
                QString dateStored = json["dateStored"].toString();

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

                // Add Edit button
                QPushButton *editButton = new QPushButton("Edit");
                connect(editButton, &QPushButton::clicked, this, [this, passId]() {
                    // Leave blank for now, as you will implement the edit dialog later
                });
                ui->tableWidget->setCellWidget(rowCount, 2, editButton);

                // Add Delete button
                QPushButton *deleteButton = new QPushButton("Delete");
                connect(deleteButton, &QPushButton::clicked, this, [this, passId, rowCount]() {
                    deletePassword(passId, rowCount);
                });
                ui->tableWidget->setCellWidget(rowCount, 3, deleteButton);

                // Set row height
                ui->tableWidget->setRowHeight(rowCount, rowHeight);
            }
        }
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
