#ifndef RETRIEVEPASSWORD_H
#define RETRIEVEPASSWORD_H

#include <QDialog>
#include <QString>
#include <QPointer>

namespace Ui {
class retrievePassword;
}

class editPasswordData;

class retrievePassword : public QDialog
{
    Q_OBJECT

public:
    explicit retrievePassword(QWidget *parent = nullptr);
    ~retrievePassword();

signals:
    // ===================
    // Signal Declarations
    // ===================
    void emitBackClicked();  // Signal emitted when the back button is clicked

private slots:
    void loadPasswords();  // Function to load and decrypt saved passwords
    void deletePassword(const QString &passId, int row);  // Function to delete a password entry
    void on_backButton_clicked();

    // New slot to handle data overwrite
    void handleOverwriteData(const QString &passId, const QString &dateStored, const QString &password, const QString &username, const QString &thoughts);

private:
    Ui::retrievePassword *ui;
    void updatePasswordEntry(const QString &oldPassId, const QString &newPassId, const QString &password, const QString &user, const QString &thoughts);
    void saveUpdatedDataToFile(const QString &oldPassId, const QString &newPassId, const QString &password, const QString &user, const QString &thoughts);
    editPasswordData *editDialog = nullptr;
};

#endif // RETRIEVEPASSWORD_H
