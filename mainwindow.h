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

// ====================
// MainWindow Class
// ====================
class MainWindow : public QMainWindow
{
    Q_OBJECT

    // ====================
    // Public Methods
    // ====================
public:
    explicit MainWindow(QWidget *parent = nullptr);  // Constructor
    ~MainWindow();  // Destructor

    // ====================
    // Signals
    // ====================
signals:
    void themeLoaded(QString theme);  // Emit theme loaded signal

    // ====================
    // Public Slots
    // ====================
public slots:
    void on_createPassSubmitButton_2_clicked();  // Handle create password button click
    void on_loginButton_4_clicked();  // Handle login button click
    void updatePassword(const QString &newPassword);  // Update password slot
    void handleUpdateTheme(QString selectedTheme);  // Handle theme update

    // ====================
    // Private Slots
    // ====================
private slots:
    void on_copyCipherButton_2_clicked();  // Handle copy cipher button click

    // ====================
    // Private Methods
    // ====================
private:
    QString passwordFilePath();  // Get password file path
    bool passwordExists();  // Check if password exists
    void createPassword(const QString &firstPassEntry, const QString &email);  // Create password
    bool saveToFile(const QByteArray &hashedPassword, const QByteArray &salt, const QByteArray &encryptedEmail, const QString &theme);  // Save to file
    void promptForPassword(const QString &password);  // Prompt for password
    bool verifyPassword(const QString &password);  // Verify password
    bool loadFromFile(QByteArray &hashedPassword, QByteArray &salt, QByteArray &encryptedEmail, QString &theme);  // Load from file
    QString generateCipherKey();  // Generate cipher key
    void maskPasswordEntry(QLineEdit *lineEdit, QString &realInput);  // Mask password entry

    // ====================
    // Private Members
    // ====================
private:
    Ui::MainWindow *ui;  // User interface pointer
    std::unique_ptr<passwordManagementButtons> myButtonsPage;  // Pointer to buttons page
    QString cachedPasswordFilePath;  // Cached password file path
};

// ====================
// External Variables
// ====================
extern QString globalCipherKey;  // Global cipher key
extern QString realPassword;  // Real password
extern QString realCipherKey;  // Real cipher key

#endif // MAINWINDOW_H
