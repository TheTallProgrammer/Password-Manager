// passwordinfodialog.h
#ifndef PASSWORDINFODIALOG_H
#define PASSWORDINFODIALOG_H

#include <QDialog>

namespace Ui {
class PasswordInfoDialog;
}

class PasswordInfoDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PasswordInfoDialog(QWidget *parent = nullptr, const QString &password = "");
    ~PasswordInfoDialog();

private slots:
    void on_copyButton_clicked();
    void on_acknowledgeButton_clicked();

private:
    Ui::PasswordInfoDialog *ui;
    QString m_password;
};

#endif // PASSWORDINFODIALOG_H
