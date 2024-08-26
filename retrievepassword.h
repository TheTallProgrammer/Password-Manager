#ifndef RETRIEVEPASSWORD_H
#define RETRIEVEPASSWORD_H

#include <QDialog>
#include <QString>
#include <QPointer>

// ====================
// Forward Declarations
// ====================
namespace Ui {
class retrievePassword;
}

class editPasswordData;

// ====================
// retrievePassword Class
// ====================
class retrievePassword : public QDialog
{
    Q_OBJECT

    // ====================
    // Public Methods
    // ====================
public:
    explicit retrievePassword(QWidget *parent = nullptr);  // Constructor
    ~retrievePassword();  // Destructor

    // ====================
    // Signal Declarations
    // ====================
signals:
    void emitBackClicked();  // Signal emitted when the back button is clicked

    // ====================
    // Private Slots
    // ====================
private slots:
    void loadPasswords();  // Load and decrypt saved passwords
    void deletePassword(const QString &passId, int row);  // Delete a password entry
    void on_backButton_clicked();  // Handle back button click

    // New slot to handle data overwrite
    void handleOverwriteData(const QString &passId, const QString &dateStored, const QString &password, const QString &username, const QString &thoughts);

    // ====================
    // Private Methods
    // ====================
private:
    void updatePasswordEntry(const QString &oldPassId, const QString &newPassId, const QString &password, const QString &user, const QString &thoughts);  // Update password entry
    void saveUpdatedDataToFile(const QString &oldPassId, const QString &newPassId, const QString &password, const QString &user, const QString &thoughts);  // Save updated data to file

    // ====================
    // Private Members
    // ====================
private:
    Ui::retrievePassword *ui;  // User interface pointer
    editPasswordData *editDialog = nullptr;  // Pointer to edit dialog
};

#endif // RETRIEVEPASSWORD_H
