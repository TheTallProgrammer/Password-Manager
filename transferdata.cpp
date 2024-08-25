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
#include "mainwindow.h"  // Include MainWindow to access its methods
// Additionally, if CryptoUtils is a custom class, include its header file
#include "cryptoutils.h"   // Assuming CryptoUtils is defined in cryptoutils.h



transferData::transferData(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::transferData)
{
    ui->setupUi(this);
}

transferData::~transferData()
{
    delete ui;
}

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
            qDebug() << "Decrypted Data:" << decryptedData;  // Debug: Check the decrypted data

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

    // Convert the aggregated JSON object to a JSON document
    QJsonDocument finalDoc(aggregatedJson);

    // Open a file dialog to allow the user to choose where to save the JSON file
    QString saveFileName = QFileDialog::getSaveFileName(this, "Export Passwords", QDir::homePath(), "JSON Files (*.json)");

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

}

