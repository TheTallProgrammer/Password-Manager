#include "storepassword.h"
#include "ui_storepassword.h"
#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include <QCryptographicHash>
#include <QByteArray>
#include <QDataStream>
#include <QDebug>
#include <QNetworkInterface>  // For getting the MAC address
#include <QStandardPaths>
#include <QDir>

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

// =====================
// UI Signal Handlers
// =====================

// Handles the back button click event
void storePassword::on_backButton_clicked()
{
    this->hide();
    emit emitBackClicked();  // Emit signal to notify back button was clicked

    // Clear UI fields
    ui->passIdText->clear();
    ui->passwordText->clear();
    ui->userText->clear();
    ui->thoughtText->clear();

    this->accept();  // Close the dialog
}

// Handles the generate password button click event
void storePassword::on_genPassButton_clicked()
{
    emit requestGenPassword();  // Emit signal to request password generation
}

// Handles the store password button click event
void storePassword::on_storePassButton_clicked()
{
    QString passId = ui->passIdText->toPlainText();
    QString password = ui->passwordText->toPlainText();

    // Ensure passId and password fields are not empty
    if (passId.isEmpty() || password.isEmpty()) {
        qDebug() << "ERROR: passId or password field is empty. Cannot store the password.";
        return;
    }

    // Create JSON object with user input data
    QJsonObject json;
    json["passId"] = passId;
    json["password"] = password;
    json["user"] = ui->userText->toPlainText();
    json["thoughts"] = ui->thoughtText->toPlainText();

    QJsonDocument doc(json);
    QByteArray jsonData = doc.toJson();

    qDebug() << "Original JSON data:" << jsonData;

    // Encrypt the JSON data
    QByteArray encryptedData = encryptData(jsonData);
    qDebug() << "Encrypted data:" << encryptedData.toHex();

    // Decrypt the data for verification
    QByteArray decryptedData = decryptData(encryptedData);
    qDebug() << "Decrypted JSON data:" << decryptedData;

    // Convert decrypted data back to JSON object for verification
    QJsonDocument decryptedDoc = QJsonDocument::fromJson(decryptedData);
    QJsonObject decryptedJson = decryptedDoc.object();
    qDebug() << "Decrypted JSON object:" << decryptedJson;

    // Save the encrypted data to a file
    saveEncryptedDataToFile(passId, encryptedData);
}

// =====================
// Encryption/Decryption Functions
// =====================

// Generates a machine-specific key using the MAC address
QByteArray storePassword::getMachineSpecificKey()
{
    QList<QNetworkInterface> interfaces = QNetworkInterface::allInterfaces();
    QByteArray macAddress;

    // Get the MAC address of the first active network interface
    for (const QNetworkInterface &iface : interfaces) {
        if (iface.flags().testFlag(QNetworkInterface::IsUp) && !iface.hardwareAddress().isEmpty()) {
            macAddress = iface.hardwareAddress().toUtf8();
            break;
        }
    }

    // Combine the MAC address with a secret key (commented out for now)
    QByteArray combinedKey = macAddress;  // + secretKey;

    // Hash the combined key to get the final key
    return QCryptographicHash::hash(combinedKey, QCryptographicHash::Sha256);
}

// Encrypts data using a simple XOR operation with a machine-specific key
QByteArray storePassword::encryptData(const QByteArray &data)
{
    QByteArray key = getMachineSpecificKey();
    QByteArray result;

    // XOR encryption process
    for (int i = 0; i < data.size(); ++i) {
        result.append(data[i] ^ key[i % key.size()]);
    }

    return result;
}

// Decrypts data using the same XOR operation with a machine-specific key
QByteArray storePassword::decryptData(const QByteArray &encryptedData)
{
    QByteArray key = getMachineSpecificKey();
    QByteArray result;

    // XOR decryption process (same as encryption)
    for (int i = 0; i < encryptedData.size(); ++i) {
        result.append(encryptedData[i] ^ key[i % key.size()]);
    }

    return result;
}

// =====================
// File Handling Functions
// =====================

// Saves encrypted data to a file in the specified directory
void storePassword::saveEncryptedDataToFile(const QString &passId, const QByteArray &encryptedData)
{
    // Determine the file path
    QString dirPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/PasswordManager";
    QString filePath = dirPath + "/" + passId + ".bin";

    // Debug output to show the file location
    qDebug() << "Attempting to save the encrypted data to file at:" << filePath;

    // Create the directory if it doesn't exist
    QDir dir(dirPath);
    if (!dir.exists()) {
        if (!dir.mkpath(".")) {
            qWarning() << "Could not create directory:" << dirPath;
            return;
        }
    }

    // Attempt to open the file for writing
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly)) {
        qWarning() << "Could not open file for writing:" << filePath;
        return;
    }

    // Write the encrypted data to the file
    QDataStream out(&file);
    out << encryptedData;
    file.close();

    qDebug() << "Password data saved and encrypted in file:" << filePath;
}
