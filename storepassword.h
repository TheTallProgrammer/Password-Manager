#ifndef STOREPASSWORD_H
#define STOREPASSWORD_H

#include <QDialog>
#include <QByteArray>
#include <QNetworkInterface>
#include <QJsonObject>

// =====================
// Namespace Declarations
// =====================
namespace Ui {
class storePassword;
}

// =====================
// Class Declaration
// =====================
class storePassword : public QDialog
{
    Q_OBJECT

public:
    // =========================
    // Constructor & Destructor
    // =========================
    explicit storePassword(QWidget *parent = nullptr);
    ~storePassword();

signals:
    // ===================
    // Signal Declarations
    // ===================
    void requestGenPassword();  // Signal to request a new password generation
    void emitBackClicked();  // Signal emitted when the back button is clicked

private slots:
    // ==================
    // Slot Declarations
    // ==================
    void on_backButton_clicked();  // Handles the back button click event
    void on_genPassButton_clicked();  // Handles the generate password button click event
    void on_storePassButton_clicked();  // Handles the store password button click event

private:
    // =====================
    // Private Members
    // =====================
    Ui::storePassword *ui;  // UI pointer for the storePassword dialog
    void closeEvent(QCloseEvent *event);

    // =====================
    // Encryption Functions
    // =====================
    QByteArray encryptData(const QByteArray &data);  // Encrypts the given data
    QByteArray decryptData(const QByteArray &encryptedData);  // Decrypts the given data

    // ============================
    // Machine-Specific Key Function
    // ============================
    QByteArray getMachineSpecificKey();  // Generates a machine-specific key
    void clearUI(); // Clears UI

    // ============================
    // File Handling Functions
    // ============================
    void saveEncryptedDataToFile(const QString &passId, const QByteArray &encryptedData);  // Saves encrypted data to a file
    QJsonObject loadAndDecryptDataFromFile(const QString &passId);  // Loads and decrypts data from a file (for testing)
};

#endif // STOREPASSWORD_H
