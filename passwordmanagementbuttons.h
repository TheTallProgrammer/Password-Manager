#ifndef PASSWORDMANAGEMENTBUTTONS_H
#define PASSWORDMANAGEMENTBUTTONS_H

#include <memory>
#include <QDialog>

class PasswordGenerator; // forward declaration
class resetPassword;
class storePassword;

namespace Ui {
class passwordManagementButtons;
}

class passwordManagementButtons : public QDialog
{
    Q_OBJECT

public:
    explicit passwordManagementButtons(QWidget *parent = nullptr);
    ~passwordManagementButtons();

private slots:
    void on_genPass_clicked();
    void onResetCanceled();  // Slot to handle reset canceled

    void on_resetLoginButton_clicked();

    void on_logoutButton_clicked();

    void on_storePass_clicked();
    void handleRequestGenPassword();  // Slot to handle password generation requests
    void handleBackStorePassword(); // slot to handle user clicking back on store pass

private:
    Ui::passwordManagementButtons *ui;
    std::unique_ptr<PasswordGenerator> myPassGen; // smart pointer
    std::unique_ptr<resetPassword> resetPass;
    std::unique_ptr<storePassword> storePass;

};

#endif // PASSWORDMANAGEMENTBUTTONS_H
