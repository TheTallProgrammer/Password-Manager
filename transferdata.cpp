#include "transferdata.h"
#include "ui_transferdata.h"
#include <QStandardPaths>  // For QStandardPaths
#include <QDir>            // For QDir and directory operations
#include <QMessageBox>     // For QMessageBox
#include <QJsonObject>     // For QJsonObject
#include <QJsonDocument>   // For QJsonDocument
#include <QFileInfo>       // For QFileInfo
#include <QFile>           // For QFile
#include <QDataStream>     // For QDataStream
#include <QDebug>          // For qDebug
#include <QFileDialog>     // For QFileDialog
#include <QString>         // For QString
#include "mainwindow.h"    // Include MainWindow to access its methods
#include "cryptoutils.h"   // Assuming CryptoUtils is defined in cryptoutils.h
#include "storepassword.h"

// =====================
// Constructor & Destructor
// =====================
transferData::transferData(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::transferData)
{
    ui->setupUi(this);
    setWindowTitle("Falkenberg's Password Manager");
}

transferData::~transferData()
{
    delete ui;
}

// =====================
// UI Signal Handlers
// =====================

void transferData::on_backButton_clicked()
{
    emit backButtonPressed();
}

void transferData::on_exportButton_clicked()
{
    QString dirPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/PasswordManager";
    QDir dir(dirPath);

    if (!dir.exists()) {
        QMessageBox::warning(this, "Export Failed", "No saved passwords found.");
        return;
    }

    QJsonObject aggregatedJson;

    // Iterate through all the files in the directory
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

            QJsonDocument jsonDoc = QJsonDocument::fromJson(decryptedData);

            if (!jsonDoc.isNull() && jsonDoc.isObject()) {
                QJsonObject jsonObject = jsonDoc.object();
                aggregatedJson.insert(item.fileName(), jsonObject);
            } else {
                qDebug() << "Failed to parse JSON for file:" << item.fileName();  // Debug: Check for JSON parsing issues
            }
        } else {
            qDebug() << "Failed to open file for reading:" << filePath;
        }
    }

    qDebug() << "Aggregated JSON:" << QJsonDocument(aggregatedJson).toJson();  // Debug: Check the final JSON

    QJsonDocument finalDoc(aggregatedJson);  // Convert the aggregated JSON object to a JSON document

    QString saveFileName = QFileDialog::getSaveFileName(this, "Export Passwords", QDir::homePath(), "JSON Files (*.json)");  // Open a file dialog to allow the user to choose where to save the JSON file

    if (!saveFileName.isEmpty()) {
        QFile saveFile(saveFileName);

        if (!saveFile.open(QIODevice::WriteOnly)) {
            QMessageBox::warning(this, "Export Failed", "Failed to open file for saving.");
            return;
        }

        saveFile.write(finalDoc.toJson());
        saveFile.close();

        QMessageBox::information(this, "Export Successful", "Passwords exported successfully.");
    }
}

void transferData::on_importButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Import Passwords", QDir::homePath(), "JSON Files (*.json)");  // Step 1: Prompt user to select a file

    if (fileName.isNull()) {
        return;  // Step 2: Check if the dialog was canceled
    }

    if (!fileName.endsWith(".json", Qt::CaseInsensitive)) {  // Step 3: Ensure the file has a .json extension
        QMessageBox::warning(this, "Import Failed", "Selected file is not a JSON file.");
        return;
    }

    QFile file(fileName);  // Step 4: Open and read the file
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, "Import Failed", "Failed to open the selected file.");
        return;
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);  // Step 5: Parse the JSON data
    if (jsonDoc.isNull() || !jsonDoc.isObject()) {
        QMessageBox::warning(this, "Import Failed", "The JSON file is not in the correct format.");
        return;
    }

    QJsonObject jsonObj = jsonDoc.object();

    // Step 6: Iterate over each key-value pair in the JSON object
    for (auto it = jsonObj.begin(); it != jsonObj.end(); ++it) {
        QString key = it.key();
        QJsonObject passwordObject = it.value().toObject();

        // Ensure the JSON object has the correct structure
        if (!passwordObject.contains("passId") || !passwordObject.contains("password") ||
            !passwordObject.contains("username") || !passwordObject.contains("thoughts") ||
            !passwordObject.contains("dateStored")) {
            QMessageBox::warning(this, "Import Failed", "One or more entries in the JSON file are not in the correct format.");
            return;
        }

        QJsonDocument passDoc(passwordObject);  // Step 7: Convert the JSON object back to a JSON string
        QByteArray passJsonData = passDoc.toJson();

        QByteArray encryptedData = CryptoUtils::encryptData(passJsonData, globalCipherKey);  // Step 8: Encrypt the JSON data using the globalCipherKey

        saveEncryptedDataToFile(passwordObject["passId"].toString(), encryptedData);  // Step 9: Save the encrypted data to the appropriate file
    }

    QMessageBox::information(this, "Import Successful", "Passwords imported successfully.");  // Step 10: Display a success message
}

// =====================
// File Handling Functions
// =====================

void transferData::saveEncryptedDataToFile(const QString &passId, const QByteArray &encryptedData)
{
    QString dirPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/PasswordManager";
    QString filePath = dirPath + "/" + passId + ".bin";

    QDir dir(dirPath);
    if (!dir.exists()) {
        if (!dir.mkpath(".")) {
            return;
        }
    }

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly)) {
        return;
    }

    QDataStream out(&file);
    out << encryptedData;
    file.close();

    QByteArray decryptedData = CryptoUtils::decryptData(encryptedData, globalCipherKey);

    QJsonDocument decryptedDoc = QJsonDocument::fromJson(decryptedData);  // Optionally convert the decrypted data back to JSON for further verification
    if (decryptedDoc.isNull()) {
        qDebug() << "Failed to convert decrypted data to JSON. The data may be corrupted or incorrectly decrypted.";
    } else {
        QJsonObject decryptedJson = decryptedDoc.object();
    }
}
