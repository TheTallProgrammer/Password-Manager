#include "storePassword.h"
#include "ui_storePassword.h"
#include "CryptoUtils.h"  // Include the utility
#include "mainwindow.h"  // Include to access globalCipherKey
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include <QDebug>
#include <QStandardPaths>
#include <QDir>
#include <QDateTime>  // Include for handling date and time
#include <QCloseEvent>

// =====================
// Constructor & Destructor
// =====================
storePassword::storePassword(QWidget *parent)
    : QDialog(parent), ui(new Ui::storePassword)
{
    ui->setupUi(this);
}

storePassword::~storePassword()
{
    delete ui;
}

void storePassword::closeEvent(QCloseEvent *event)
{
    QCoreApplication::quit();  // Quit the entire application
    event->accept();  // Accept the event, allowing the window to close
}

// =====================
// UI Signal Handlers
// =====================

void storePassword::on_backButton_clicked()
{
    this->hide();
    emit emitBackClicked();  // Emit signal to notify back button was clicked
    clearUI();
    this->accept();  // Close the dialog
}

void storePassword::clearUI(){
    // Clear UI fields
    ui->passIdText->clear();
    ui->passwordText->clear();
    ui->userText->clear();
    ui->thoughtText->clear();
}

void storePassword::on_genPassButton_clicked()
{
    emit requestGenPassword();  // Emit signal to request password generation
}

void storePassword::on_storePassButton_clicked()
{
    QString passId = ui->passIdText->toPlainText();
    QString password = ui->passwordText->toPlainText();

    // Ensure passId and password fields are not empty
    if (passId.isEmpty() || password.isEmpty()) {
        qDebug() << "ERROR: passId or password field is empty. Cannot store the password.";
        return;
    }

    // Get the current date and time as a string
    QString dateStored = QDateTime::currentDateTime().toString(Qt::ISODate);

    // Create JSON object with user input data and the current date
    QJsonObject json;
    json["passId"] = passId;
    json["password"] = password;
    json["user"] = ui->userText->toPlainText();
    json["thoughts"] = ui->thoughtText->toPlainText();
    json["dateStored"] = dateStored;  // Add the date to the JSON object

    QJsonDocument doc(json);
    QByteArray jsonData = doc.toJson();

    // Show the original data before encryption
    qDebug() << "Original JSON data:" << jsonData;

    // Encrypt the JSON data using CryptoUtils with globalCipherKey from MainWindow
    QByteArray encryptedData = CryptoUtils::encryptData(jsonData, globalCipherKey, 10);
    qDebug() << "Encrypted data (hex):" << encryptedData.toHex();

    // Save the encrypted data to a file
    saveEncryptedDataToFile(passId, encryptedData);
    clearUI();
    this->hide();
    emit emitBackClicked();
    this->accept();
}

// =====================
// File Handling Functions
// =====================

void storePassword::saveEncryptedDataToFile(const QString &passId, const QByteArray &encryptedData)
{
    QString dirPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/PasswordManager";
    QString filePath = dirPath + "/" + passId + ".bin";

    qDebug() << "Attempting to save the encrypted data to file at:" << filePath;

    QDir dir(dirPath);
    if (!dir.exists()) {
        if (!dir.mkpath(".")) {
            qWarning() << "Could not create directory:" << dirPath;
            return;
        }
    }

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly)) {
        qWarning() << "Could not open file for writing:" << filePath;
        return;
    }

    QDataStream out(&file);
    out << encryptedData;
    file.close();

    qDebug() << "Password data saved and encrypted in file:" << filePath;

    // Decrypt the data to verify it can be correctly decrypted
    QByteArray decryptedData = CryptoUtils::decryptData(encryptedData, globalCipherKey, 10);
    qDebug() << "Decrypted data (raw):" << decryptedData;

    // Optionally convert the decrypted data back to JSON for further verification
    QJsonDocument decryptedDoc = QJsonDocument::fromJson(decryptedData);
    if (decryptedDoc.isNull()) {
        qDebug() << "Failed to convert decrypted data to JSON. The data may be corrupted or incorrectly decrypted.";
    } else {
        QJsonObject decryptedJson = decryptedDoc.object();
        qDebug() << "Decrypted JSON object:" << decryptedJson;
    }
}
