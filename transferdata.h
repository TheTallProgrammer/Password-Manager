#ifndef TRANSFERDATA_H
#define TRANSFERDATA_H

#include <QDialog>

// ====================
// Forward Declarations
// ====================
namespace Ui {
class transferData;
}

// ====================
// transferData Class
// ====================
class transferData : public QDialog
{
    Q_OBJECT

    // ====================
    // Public Methods
    // ====================
public:
    explicit transferData(QWidget *parent = nullptr);  // Constructor
    ~transferData();  // Destructor

    // ====================
    // Signal Declarations
    // ====================
signals:
    void backButtonPressed();  // Signal emitted when the back button is pressed

    // ====================
    // Private Slots
    // ====================
private slots:
    void on_backButton_clicked();  // Handle back button click
    void on_exportButton_clicked();  // Handle export button click
    void on_importButton_clicked();  // Handle import button click

    // ====================
    // Private Methods
    // ====================
private:
    void saveEncryptedDataToFile(const QString &passId, const QByteArray &encryptedData);  // Save encrypted data to file

    // ====================
    // Private Members
    // ====================
private:
    Ui::transferData *ui;  // User interface pointer
};

#endif // TRANSFERDATA_H
