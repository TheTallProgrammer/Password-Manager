#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QInputDialog>
#include <QMessageBox>
#include <QCryptographicHash>
#include <QDateTime>
#include <QRandomGenerator>
#include <QFile>
#include <QStandardPaths>
#include <QDir>
#include <QColorDialog>
#include <QClipboard>
#include <memory>
#include "passwordgenerator.h"
#include "passwordmanagementbuttons.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

// =============================================================
// MainWindow Class Definition
// =============================================================
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // =============================================================
    // Constructor and Destructor
    // =============================================================
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    // =============================================================
    // Public Slots
    // =============================================================
    void on_createPassSubmitButton_2_clicked();  // Slot connected to create password button
    void on_loginButton_4_clicked();  // Slot connected to login button
    void updatePassword(const QString &newPassword);  // Slot to update the password in UI or other components

private slots:
    // =============================================================
    // Private Slots
    // =============================================================
    void on_copyCipherButton_2_clicked();  // Slot connected to copy cipher button

private:
    // =============================================================
    // Private Members
    // =============================================================
    Ui::MainWindow *ui;  // Pointer to the UI elements
    std::unique_ptr<passwordManagementButtons> myButtonsPage;  // Smart pointer to manage password management buttons
    QString cachedPasswordFilePath;  // Cached file path for performance optimization

    // =============================================================
    // Private Methods
    // =============================================================
    QString passwordFilePath();  // Returns the file path where the password is stored
    bool passwordExists();  // Checks if the password file exists
    void createPassword(QString password);  // Creates a password file with the given password
    QByteArray generateSalt();  // Generates a random salt for password hashing
    QByteArray hashPassword(const QString &password, const QByteArray &salt);  // Hashes the password with the given salt
    bool saveToFile(const QByteArray &hashedPassword, const QByteArray &salt);  // Saves the hashed password and salt to a file
    void promptForPassword(const QString &password);  // Prompts the user to enter their password
    bool verifyPassword(const QString &password);  // Verifies if the entered password matches the saved password
    bool loadFromFile(QByteArray &hashedPassword, QByteArray &salt);  // Loads the hashed password and salt from a file
    QString generateCipherKey();  // Generates a cipher key for encryption

};

// =============================================================
// Global Variables
// =============================================================
extern QString globalCipherKey;  // Global variable for the cipher key (Consider refactoring to avoid global state)

#endif // MAINWINDOW_H
