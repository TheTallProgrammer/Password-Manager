#ifndef EDITPASSWORDDATA_H
#define EDITPASSWORDDATA_H

#include <QDialog>

// ====================
// Namespace
// ====================
namespace Ui {
class editPasswordData; // Forward declaration of the editPasswordData class
}

// ====================
// Class Declaration
// ====================
class editPasswordData : public QDialog
{
    Q_OBJECT // Enable Qt's signal and slot mechanism

public:
    // ====================
    // Public Methods
    // ====================
    explicit editPasswordData(QWidget *parent = nullptr,  QString passId = "_passid",  QString dateStored = "_date",  QString password = "_password",  QString username = "_username",  QString thoughts = "_thoughts"); // Constructor with default parameters
    ~editPasswordData(); // Destructor

signals:
    // ====================
    // Signals
    // ====================
    void overwriteData(const QString &passId, const QString &dateStored, const QString &password, const QString &username, const QString &thoughts); // Signal to overwrite data

private slots:
    // ====================
    // Private Slots
    // ====================
    void on_backButton_clicked(); // Slot for back button click
    void on_saveButton_clicked(); // Slot for save button click

private:
    // ====================
    // Private Members
    // ====================
    Ui::editPasswordData *ui; // Pointer to the UI
};

#endif // EDITPASSWORDDATA_H
