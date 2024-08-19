#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QInputDialog>
#include <QMessageBox>
#include <QCryptographicHash>
#include <QDateTime>
#include <QRandomGenerator>
#include <QFile>
#include <QStandardPaths>
#include <QDir>
#include <QColorDialog>
#include <memory>
#include "passwordgenerator.h"
#include "passwordmanagementbuttons.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void on_createPassSubmitButton_clicked();
    void on_loginButton_clicked();
    void updatePassword(const QString &newPassword);  // Slot to update the password

private:
    Ui::MainWindow *ui;
    QString passwordFilePath();
    bool passwordExists();
    void createPassword(QString);
    QByteArray generateSalt();
    QByteArray hashPassword(const QString &password, const QByteArray &salt);
    bool saveToFile(const QByteArray &hashedPassword, const QByteArray &salt);
    void promptForPassword(const QString &password);  // Pass by reference to avoid copying
    bool verifyPassword(const QString &password);
    bool loadFromFile(QByteArray &hashedPassword, QByteArray &salt);

    std::unique_ptr<passwordManagementButtons> myButtonsPage;

    QString cachedPasswordFilePath;  // Cached file path for performance optimization
};

#endif // MAINWINDOW_H
