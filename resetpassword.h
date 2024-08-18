#ifndef RESETPASSWORD_H
#define RESETPASSWORD_H

#include <QDialog>

namespace Ui {
class resetPassword;
}

class resetPassword : public QDialog
{
    Q_OBJECT

public:
    explicit resetPassword(QWidget *parent = nullptr);
    ~resetPassword();

signals:
    void resetCanceled();  // Signal emitted when cancel is clicked
    void passwordUpdated(const QString &newPassword);  // Signal to send the new password

private slots:
    void on_cancelButton_clicked();

    void on_confirmButton_clicked();

private:
    Ui::resetPassword *ui;
};

#endif // RESETPASSWORD_H
