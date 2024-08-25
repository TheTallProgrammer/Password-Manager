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
#include <QClipboard>
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
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void themeLoaded(QString theme);
    void updateThemeComboBox(QString theme);

public slots:
    void on_createPassSubmitButton_2_clicked();
    void on_loginButton_4_clicked();
    void updatePassword(const QString &newPassword);
    void handleUpdateTheme(QString selectedTheme);

private slots:
    void on_copyCipherButton_2_clicked();

private:
    Ui::MainWindow *ui;
    std::unique_ptr<passwordManagementButtons> myButtonsPage;
    QString cachedPasswordFilePath;

    QString passwordFilePath();
    bool passwordExists();
    void createPassword(const QString &firstPassEntry, const QString &email);
    bool saveToFile(const QByteArray &hashedPassword, const QByteArray &salt, const QByteArray &encryptedEmail, const QString &theme);
    void promptForPassword(const QString &password);
    bool verifyPassword(const QString &password);
    bool loadFromFile(QByteArray &hashedPassword, QByteArray &salt, QByteArray &encryptedEmail, QString &theme);
    QString generateCipherKey();
};

extern QString globalCipherKey;

#endif // MAINWINDOW_H
