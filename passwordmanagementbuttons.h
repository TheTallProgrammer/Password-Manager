#ifndef PASSWORDMANAGEMENTBUTTONS_H
#define PASSWORDMANAGEMENTBUTTONS_H

#include <memory>
#include <QDialog>

class PasswordGenerator; // forward declaration

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


    void on_resetLoginButton_clicked();

private:
    Ui::passwordManagementButtons *ui;
    std::unique_ptr<PasswordGenerator> myPassGen; // smart pointer
};

#endif // PASSWORDMANAGEMENTBUTTONS_H
