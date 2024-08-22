#ifndef PASSWORDMANAGEMENTBUTTONS_H
#define PASSWORDMANAGEMENTBUTTONS_H

#include <memory>    // Required for smart pointers
#include <QDialog>   // Required for QDialog
#include <QPointer>

// =====================
// Forward Declarations
// =====================
class PasswordGenerator;  // Forward declaration for PasswordGenerator class
class resetPassword;      // Forward declaration for resetPassword class
class storePassword;      // Forward declaration for storePassword class
class retrievePassword;

namespace Ui {
class passwordManagementButtons;
}

// ====================
// Class Declaration
// ====================
class passwordManagementButtons : public QDialog
{
    Q_OBJECT

public:
    // =========================
    // Constructor & Destructor
    // =========================
    explicit passwordManagementButtons(QWidget *parent = nullptr);
    ~passwordManagementButtons();

private slots:
    // ====================
    // Button Click Handlers
    // ====================
    void on_genPass_clicked();  // Handles the 'Generate Password' button click
    void onResetCanceled();  // Handles the reset process when canceled
    void on_resetLoginButton_clicked();  // Handles the 'Reset Login' button click
    void on_logoutButton_clicked();  // Handles the 'Logout' button click
    void on_storePass_clicked();  // Handles the 'Store Password' button click
    void handleRequestGenPassword();  // Handles password generation requests
    void handleBackStorePassword();  // Handles user clicking 'Back' in the store password section
    void handleBackRetrievePassword();  // Handles user clicking 'Back' in the store password section

    void on_retrievePass_clicked();

    void on_deleteAllButton_clicked();

    void on_exportPassButton_clicked();

private:
    // =====================
    // Private Members
    // =====================
    Ui::passwordManagementButtons *ui;  // UI pointer for managing the interface

    // Smart pointers to manage instances of related classes
    std::unique_ptr<PasswordGenerator> myPassGen;
    std::unique_ptr<resetPassword> resetPass;
    std::unique_ptr<storePassword> storePass;
    QPointer<retrievePassword> retrievePass;
    void closeEvent(QCloseEvent *event);
};

#endif // PASSWORDMANAGEMENTBUTTONS_H
