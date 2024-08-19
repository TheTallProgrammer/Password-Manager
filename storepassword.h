#ifndef STOREPASSWORD_H
#define STOREPASSWORD_H

#include <QDialog>
#include <QByteArray>
#include <QNetworkInterface>

namespace Ui {
class storePassword;
}

class storePassword : public QDialog
{
    Q_OBJECT

public:
    explicit storePassword(QWidget *parent = nullptr);
    ~storePassword();

signals:
    void requestGenPassword();
    void emitBackClicked();

private slots:
    void on_backButton_clicked();
    void on_genPassButton_clicked();
    void on_storePassButton_clicked();

private:
    Ui::storePassword *ui;

    // Encryption and Decryption functions
    QByteArray encryptData(const QByteArray &data);
    QByteArray decryptData(const QByteArray &encryptedData);

    // Function to get a machine-specific key
    QByteArray getMachineSpecificKey();

    // Function to save encrypted data to a file
    void saveEncryptedDataToFile(const QString &passId, const QByteArray &encryptedData);

    // Function to load and decrypt data from a file (for testing)
    QJsonObject loadAndDecryptDataFromFile(const QString &passId);
};

#endif // STOREPASSWORD_H
