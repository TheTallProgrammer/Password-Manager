#ifndef RESETPASSWORD_H
#define RESETPASSWORD_H

#include <QDialog>

// =====================
// Namespace Declarations
// =====================
namespace Ui {
class resetPassword;
}

// =====================
// Class Declaration
// =====================
class resetPassword : public QDialog
{
    Q_OBJECT

public:
    // =========================
    // Constructor & Destructor
    // =========================
    explicit resetPassword(QWidget *parent = nullptr);
    ~resetPassword();

signals:
    // ===================
    // Signal Declarations
    // ===================
    void resetCanceled();  // Signal emitted when the cancel button is clicked
    void passwordUpdated(const QString &newPassword);  // Signal to send the new password when confirmed

private slots:
    // ==================
    // Slot Declarations
    // ==================
    void on_cancelButton_clicked();  // Handles the cancel button click event
    void on_confirmButton_clicked();  // Handles the confirm button click event

private:
    // =====================
    // Private Members
    // =====================
    Ui::resetPassword *ui;  // UI pointer for the resetPassword dialog
};

#endif // RESETPASSWORD_H
