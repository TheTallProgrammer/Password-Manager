#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRandomGenerator>
#include "resetpassword.h"
#include <QDebug>  // Include for debugging

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , myButtonsPage(std::make_unique<passwordManagementButtons>(this))
    , cachedPasswordFilePath(QString())
{
    ui->setupUi(this);
    ui->createPass->hide();
    ui->login->hide();

    // UI Color setup
    QPalette errorPalette = ui->creationError->palette();
    errorPalette.setColor(QPalette::WindowText, Qt::red);  // Set to red or any other color
    ui->creationError->setPalette(errorPalette);
    ui->loginErrorLabel->setPalette(errorPalette);
    ui->creationError->hide();
    ui->loginErrorLabel->hide();

    if (!passwordExists()){
        ui->createPass->show();
    } else {
        ui->login->show();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_createPassSubmitButton_clicked()
{
    QString firstPassEntry = ui->createPassEntry1->text();
    QString secondPassEntry = ui->createPassEntry2->text();

    int firstLen = firstPassEntry.length();
    int secondLen = secondPassEntry.length();

    if (firstLen < 8 || secondLen < 8){ // passwords aren't long enough
        ui->creationError->setText("ERROR: Passwords must have at least 8 characters.");
        ui->creationError->show();
    }
    else if (firstPassEntry != secondPassEntry){ // passwords don't match
        ui->creationError->setText("ERROR: Passwords Don't Match.");
        ui->creationError->show();
    } else {
        ui->creationError->hide();
        createPassword(firstPassEntry);
    }
}

void MainWindow::updatePassword(const QString &newPassword)
{
#ifdef QT_DEBUG
    qDebug() << "Received signal to update password.";  // Debug statement
#endif

    // Reuse the createPassword function to update the password
    createPassword(newPassword);

#ifdef QT_DEBUG
    qDebug() << "Password updated.";  // Debug statement
#endif
}

QString MainWindow::passwordFilePath(){
    if (cachedPasswordFilePath.isEmpty()) {
        QString configDir = QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation);
        QDir dir(configDir);
        if (!dir.exists()){
            dir.mkpath(".");
        }
        cachedPasswordFilePath = dir.filePath("pass.bin");
    }
    return cachedPasswordFilePath;
}

bool MainWindow::passwordExists(){
    QFile file(passwordFilePath());
    return file.exists();
}

void MainWindow::createPassword(QString firstPassEntry) {
    QByteArray salt = generateSalt();
    QByteArray hashedPassword = hashPassword(firstPassEntry, salt);

#ifdef QT_DEBUG
    qDebug() << "Generated salt:" << salt.toHex();  // Debug statement
    qDebug() << "Hashed password:" << hashedPassword.toHex();  // Debug statement
    qDebug() << "Attempting to save password to file...";  // Debug statement
#endif

    bool passSaved = saveToFile(hashedPassword, salt);

    if (passSaved) {
        ui->creationError->setText("Password Created Successfully");
#ifdef QT_DEBUG
        qDebug() << "Password saved successfully.";  // Debug statement
#endif
    } else {
        ui->creationError->setText("Password Couldn't Save.");
#ifdef QT_DEBUG
        qDebug() << "Failed to save password.";  // Debug statement
#endif
    }

    myButtonsPage->show(); // Display the buttons page
    this->hide();
}

bool MainWindow::saveToFile(const QByteArray &hashedPassword, const QByteArray &salt) {
    const QString &filePath = passwordFilePath();
#ifdef QT_DEBUG
    qDebug() << "Saving to file path:" << filePath;  // Debug statement
#endif

    QFile file(filePath);

    // Attempt to remove the file first if it exists, to ensure a fresh write
    if (file.exists()) {
        if (!file.remove()) {
#ifdef QT_DEBUG
            qDebug() << "Failed to remove existing file.";  // Debug statement
#endif
            return false;
        } else {
#ifdef QT_DEBUG
            qDebug() << "Existing file removed.";  // Debug statement
#endif
        }
    }

    // Open the file for writing and ensure it is truncated to overwrite existing data
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
#ifdef QT_DEBUG
        qDebug() << "Failed to open file for writing.";  // Debug statement
#endif
        return false;
    }

    QDataStream out(&file);
    out << hashedPassword << salt;
    file.close();

#ifdef QT_DEBUG
    qDebug() << "Successfully wrote to file.";  // Debug statement
#endif
    return true;
}

void MainWindow::on_loginButton_clicked()
{
    QString password = ui->passwordLoginEntry->text();
    if (password.length() < 8){
        ui->loginErrorLabel->show();
        ui->loginErrorLabel->setText("Password Length Insufficient.");
    } else {
        ui->loginErrorLabel->hide();
        promptForPassword(password);
    }
}

void MainWindow::promptForPassword(const QString &password){
    if (verifyPassword(password)){
        myButtonsPage->show();
        this->hide();
    } else {
        ui->loginErrorLabel->setText("Incorrect Password.");
        ui->loginErrorLabel->show();
    }
}

bool MainWindow::verifyPassword(const QString &password) {
    QByteArray savedHashedPassword, salt;
    if (!loadFromFile(savedHashedPassword, salt)) {
#ifdef QT_DEBUG
        qDebug() << "Failed to load saved password.";  // Debug statement
#endif
        return false;
    }
    QByteArray hashedPassword = hashPassword(password, salt);
    return hashedPassword == savedHashedPassword;
}

bool MainWindow::loadFromFile(QByteArray &hashedPassword, QByteArray &salt) {
    QFile file(passwordFilePath());
    if (!file.open(QIODevice::ReadOnly)) {
#ifdef QT_DEBUG
        qDebug() << "Failed to open file for reading.";  // Debug statement
#endif
        return false;
    }

    QDataStream in(&file);
    in >> hashedPassword >> salt;
    file.close();
    return true;
}

// Password Encryption ---
QByteArray MainWindow::generateSalt() {
    return QCryptographicHash::hash(QByteArray::number(QDateTime::currentMSecsSinceEpoch()), QCryptographicHash::Sha256);
}

QByteArray MainWindow::hashPassword(const QString &password, const QByteArray &salt) {
    return QCryptographicHash::hash(password.toUtf8() + salt, QCryptographicHash::Sha256);
}
// ---
