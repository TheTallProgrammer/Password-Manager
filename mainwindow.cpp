#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "CryptoUtils.h"  // Include the utility
#include <QDebug>  // Include for debugging

QString globalCipherKey;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , myButtonsPage(std::make_unique<passwordManagementButtons>(this))
    , cachedPasswordFilePath(QString())
{
    ui->setupUi(this);
    ui->createPass->hide();
    ui->login->hide();

    QPalette errorPalette = ui->creationError_2->palette();
    errorPalette.setColor(QPalette::WindowText, Qt::red);
    ui->creationError_2->setPalette(errorPalette);
    ui->loginErrorLabel_4->setPalette(errorPalette);
    ui->creationError_2->hide();
    ui->loginErrorLabel_4->hide();

    if (!passwordExists()) {
        globalCipherKey = CryptoUtils::generateShortKey(7);  // Generate a shorter, more user-friendly cipher key
        ui->cipherKeyText_2->setText(globalCipherKey);
        ui->createPass->show();
    } else {
        ui->login->show();
    }
}

MainWindow::~MainWindow()
{
    globalCipherKey.clear();
    delete ui;
}

// Removed generateCipherKey() as it's now handled by CryptoUtils

void MainWindow::on_createPassSubmitButton_2_clicked()
{
    QString firstPassEntry = ui->createPassEntry1_2->text();
    QString secondPassEntry = ui->createPassEntry2_2->text();
    QString email = ui->emailLabel_2->text();

    if (firstPassEntry.length() < 8 || secondPassEntry.length() < 8) {
        ui->creationError_2->setText("ERROR: Passwords must have at least 8 characters.");
        ui->creationError_2->show();
    }
    else if (firstPassEntry != secondPassEntry) {
        ui->creationError_2->setText("ERROR: Passwords Don't Match.");
        ui->creationError_2->show();
    } else {
        ui->creationError_2->hide();
        createPassword(firstPassEntry, email);
    }
}

void MainWindow::createPassword(const QString &firstPassEntry, const QString &email) {
    QByteArray salt = CryptoUtils::hashData(QByteArray::number(QDateTime::currentMSecsSinceEpoch()), QByteArray());
    QByteArray hashedPassword = CryptoUtils::hashData(firstPassEntry.toUtf8(), salt);
    QByteArray encryptedEmail = CryptoUtils::encryptData(email.toUtf8(), globalCipherKey); // No keyLength needed

#ifdef QT_DEBUG
    qDebug() << "Generated salt:" << salt.toHex();
    qDebug() << "Hashed password:" << hashedPassword.toHex();
    qDebug() << "Encrypted email:" << encryptedEmail.toHex();
#endif

    bool passSaved = saveToFile(hashedPassword, salt, encryptedEmail);

    if (passSaved) {
        ui->creationError_2->setText("Password Created Successfully");
#ifdef QT_DEBUG
        qDebug() << "Password and email saved successfully.";
#endif
    } else {
        ui->creationError_2->setText("Password Couldn't Save.");
#ifdef QT_DEBUG
        qDebug() << "Failed to save password and email.";
#endif
    }

    myButtonsPage->show();
    this->hide();
}

bool MainWindow::saveToFile(const QByteArray &hashedPassword, const QByteArray &salt, const QByteArray &encryptedEmail) {
    const QString &filePath = passwordFilePath();

    QFile file(filePath);

    if (file.exists()) {
        if (!file.remove()) {
            return false;
        }
    }

    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
        return false;
    }

    QDataStream out(&file);
    out << hashedPassword << salt << encryptedEmail;
    file.close();

    return true;
}

void MainWindow::on_loginButton_4_clicked()
{
    QString password = ui->passwordLoginEntry_4->text();
    QString enteredCipherKey = ui->cipherText->text();

    if (password.length() < 8) {
        ui->loginErrorLabel_4->show();
        ui->loginErrorLabel_4->setText("Password Length Insufficient.");
    } else if (enteredCipherKey.isEmpty()) {
        ui->loginErrorLabel_4->show();
        ui->loginErrorLabel_4->setText("Cipher Key Required.");
    } else {
        ui->loginErrorLabel_4->hide();
        globalCipherKey = enteredCipherKey;
        promptForPassword(password);
    }
}

void MainWindow::promptForPassword(const QString &password) {
    if (verifyPassword(password)) {
        myButtonsPage->show();
        this->hide();
    } else {
        ui->loginErrorLabel_4->setText("Incorrect Password.");
        ui->loginErrorLabel_4->show();
    }
}

bool MainWindow::verifyPassword(const QString &password) {
    QByteArray savedHashedPassword, salt, encryptedEmail;
    if (!loadFromFile(savedHashedPassword, salt, encryptedEmail)) {
        return false;
    }
    QByteArray hashedPassword = CryptoUtils::hashData(password.toUtf8(), salt);
    return hashedPassword == savedHashedPassword;
}

bool MainWindow::loadFromFile(QByteArray &hashedPassword, QByteArray &salt, QByteArray &encryptedEmail) {
    QFile file(passwordFilePath());
    if (!file.open(QIODevice::ReadOnly)) {
        return false;
    }

    QDataStream in(&file);
    in >> hashedPassword >> salt >> encryptedEmail;
    file.close();
    return true;
}

QString MainWindow::passwordFilePath() {
    if (cachedPasswordFilePath.isEmpty()) {
        QString configDir = QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation);
        QDir dir(configDir);
        if (!dir.exists()) {
            dir.mkpath(".");
        }
        cachedPasswordFilePath = dir.filePath("login.bin");
    }
    return cachedPasswordFilePath;
}

bool MainWindow::passwordExists() {
    QFile file(passwordFilePath());
    return file.exists();
}

void MainWindow::updatePassword(const QString &newPassword) {
#ifdef QT_DEBUG
    qDebug() << "Received signal to update password.";
#endif
    createPassword(newPassword, QString()); // Pass empty email since it's just an update
#ifdef QT_DEBUG
    qDebug() << "Password updated.";
#endif
}

void MainWindow::on_copyCipherButton_2_clicked()
{
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(ui->cipherKeyText_2->text());
}
