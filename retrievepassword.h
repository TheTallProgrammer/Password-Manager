#ifndef RETRIEVEPASSWORD_H
#define RETRIEVEPASSWORD_H

#include <QDialog>
#include <QString>
#include <QPointer>

namespace Ui {
class retrievePassword;
}

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

private:
    Ui::retrievePassword *ui;
};

#endif // RETRIEVEPASSWORD_H
