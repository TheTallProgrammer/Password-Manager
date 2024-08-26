#ifndef PASSWORDINFO_H
#define PASSWORDINFO_H

#include <QDialog>

// ====================
// Forward Declarations
// ====================
namespace Ui {
class passwordInfo;
}

// ====================
// passwordInfo Class
// ====================
class passwordInfo : public QDialog
{
    Q_OBJECT

    // ====================
    // Public Methods
    // ====================
public:
    explicit passwordInfo(QWidget *parent = nullptr, const QString &password = "");  // Constructor
    ~passwordInfo();  // Destructor

    // ====================
    // Private Slots
    // ====================
private slots:
    void on_copyButton_clicked();  // Handle copy button click
    void on_acknowledgeButton_clicked();  // Handle acknowledge button click

    // ====================
    // Private Members
    // ====================
private:
    Ui::passwordInfo *ui;  // User interface pointer
    QString m_password;  // Stored password
};

#endif // PASSWORDINFO_H
