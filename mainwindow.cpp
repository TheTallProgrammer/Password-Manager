#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "CryptoUtils.h"  // Include the utility
#include <QDebug>  // Include for debugging
#include <QRegularExpression>  // Include for regex support
#include "passwordinfo.h"
#include <QTimer>

// ====================
// Global Variables
// ====================
QString globalCipherKey;  // Global cipher key
QString realPassword;  // Global real password
QString realCipherKey;  // Global real cipher key

// ====================
// Constructor
// ====================
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , myButtonsPage(std::make_unique<passwordManagementButtons>(this))
    , cachedPasswordFilePath(QString())
{
    ui->setupUi(this);
    ui->createPass->hide();
    ui->login->hide();
    setWindowTitle("Falkenberg's Password Manager");

    QPalette errorPalette = ui->creationError_2->palette();
    errorPalette.setColor(QPalette::WindowText, Qt::red);
    ui->creationError_2->setPalette(errorPalette);
    ui->loginErrorLabel_4->setPalette(errorPalette);
    ui->creationError_2->hide();
    ui->loginErrorLabel_4->hide();

    QByteArray hashedPassword, salt, encryptedEmail;
    QString savedTheme;

    if (!passwordExists()) {
        globalCipherKey = CryptoUtils::generateShortKey(7);  // Generate a shorter, more user-friendly cipher key
        ui->cipherKeyText_2->setText(globalCipherKey);
        ui->createPass->show();

        // Apply the default theme "Light"
        handleUpdateTheme("Light");
    } else {
        if (loadFromFile(hashedPassword, salt, encryptedEmail, savedTheme)) {
            handleUpdateTheme(savedTheme);  // Apply the saved theme
        }
        ui->login->show();
    }

    // Connect the updateTheme signal to the handleUpdateTheme slot
    connect(myButtonsPage.get(), &passwordManagementButtons::updateTheme,
            this, &MainWindow::handleUpdateTheme);

    connect(ui->passwordLoginEntry_4, &QLineEdit::textChanged, this, [this]() {
        maskPasswordEntry(ui->passwordLoginEntry_4, realPassword);
    });

    connect(ui->cipherText, &QLineEdit::textChanged, this, [this]() {
        maskPasswordEntry(ui->cipherText, realCipherKey);
    });
}

// ====================
// Destructor
// ====================
MainWindow::~MainWindow()
{
    globalCipherKey.clear();
    delete ui;
}

// ====================
// Private Methods
// ====================

void MainWindow::maskPasswordEntry(QLineEdit *lineEdit, QString &realInput)
{
    QString currentText = lineEdit->text();
    int length = currentText.length();

    // Calculate the number of new characters added
    int newCharsCount = length - realInput.length();

    if (newCharsCount > 0) {
        // Append the new characters to realInput
        realInput += currentText.right(newCharsCount);
    } else if (newCharsCount < 0) {
        // If characters were deleted, adjust realInput accordingly
        realInput = realInput.left(length);
    }

    QString maskedText;
    if (length > 1) {
        maskedText = QString(length - 1, '*') + currentText.right(1);
    } else {
        maskedText = currentText;
    }

    lineEdit->blockSignals(true);  // Prevent recursion
    lineEdit->setText(maskedText);
    lineEdit->blockSignals(false);
    lineEdit->setCursorPosition(length);  // Ensure cursor stays at the end
}

void MainWindow::handleUpdateTheme(QString selectedTheme)
{
    QString themeFilePath;

    if (selectedTheme == "Nightshade") {
        themeFilePath = "../../nightshadeTheme.qss";
    } else if (selectedTheme == "Amethyst") {
        themeFilePath = "../../amethystTheme.qss";
    } else if (selectedTheme == "Light") {
        themeFilePath = "../../lightTheme.qss";
    } else if (selectedTheme == "Sunset") {
        themeFilePath = "../../solarTheme.qss";
    } else {
        qDebug() << "Unknown theme selected.";
        return;
    }

    QFile file(themeFilePath);
    if (file.open(QFile::ReadOnly)) {
        QString style = QLatin1String(file.readAll());
        qApp->setStyleSheet(style);
        file.close();
        qDebug() << selectedTheme << " theme applied successfully.";

        // Save the selected theme to the file
        QByteArray hashedPassword, salt, encryptedEmail;
        QString currentTheme;
        if (loadFromFile(hashedPassword, salt, encryptedEmail, currentTheme)) {
            saveToFile(hashedPassword, salt, encryptedEmail, selectedTheme);
        }
    } else {
        qDebug() << "File does not exist at path:" << file.fileName();
    }
}

void MainWindow::createPassword(const QString &firstPassEntry, const QString &email) {
    QByteArray salt = CryptoUtils::hashData(QByteArray::number(QDateTime::currentMSecsSinceEpoch()), QByteArray());
    QByteArray hashedPassword = CryptoUtils::hashData(firstPassEntry.toUtf8(), salt);
    QByteArray encryptedEmail = CryptoUtils::encryptData(email.toUtf8(), globalCipherKey);  // No keyLength needed
    QString defaultTheme = "Light";  // Default theme

    bool passSaved = saveToFile(hashedPassword, salt, encryptedEmail, defaultTheme);

    if (passSaved) {
        ui->creationError_2->setText("Password Created Successfully");
        passwordInfo infoDialog(this, firstPassEntry);
        infoDialog.exec();  // This should display the dialog modally

    } else {
        ui->creationError_2->setText("Password Couldn't Save.");
    }

    myButtonsPage->show();
    this->hide();
}

bool MainWindow::saveToFile(const QByteArray &hashedPassword, const QByteArray &salt, const QByteArray &encryptedEmail, const QString &theme) {
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
    out << theme;  // Save the selected theme as plain text
    file.close();

    return true;
}

bool MainWindow::verifyPassword(const QString &password) {
    QByteArray savedHashedPassword, salt, encryptedEmail;
    QString loadedTheme;  // Temporary variable to load the theme
    if (!loadFromFile(savedHashedPassword, salt, encryptedEmail, loadedTheme)) {
        return false;
    }
    QByteArray hashedPassword = CryptoUtils::hashData(password.toUtf8(), salt);
    return hashedPassword == savedHashedPassword;
}

bool MainWindow::loadFromFile(QByteArray &hashedPassword, QByteArray &salt, QByteArray &encryptedEmail, QString &theme) {
    QFile file(passwordFilePath());
    if (!file.open(QIODevice::ReadOnly)) {
        return false;
    }

    QDataStream in(&file);
    in >> hashedPassword >> salt >> encryptedEmail;
    in >> theme;  // Load the saved theme
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

// ====================
// Public Slots
// ====================

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

void MainWindow::on_loginButton_4_clicked()
{
    // Use the actual password and cipher key stored in realPassword and realCipherKey
    QString enteredPassword = realPassword;
    QString enteredCipherKey = realCipherKey;

    // Regular expression to check if the cipher key contains only letters and numbers
    QRegularExpression alphanumericRegex("^[a-zA-Z0-9]+$");

    if (enteredPassword.length() < 8) {
        ui->loginErrorLabel_4->show();
        ui->loginErrorLabel_4->setText("Password Length Insufficient.");
    } else if (enteredCipherKey.isEmpty()) {
        ui->loginErrorLabel_4->show();
        ui->loginErrorLabel_4->setText("Cipher Key Required.");
    } else if (enteredCipherKey.length() < 6) {
        ui->loginErrorLabel_4->show();
        ui->loginErrorLabel_4->setText("Cipher Key Length Too Short. Six Character Minimum.");
    } else if (!alphanumericRegex.match(enteredCipherKey).hasMatch()) {
        ui->loginErrorLabel_4->show();
        ui->loginErrorLabel_4->setText("Cipher Key Invalid. No Symbols Allowed.");
    } else {
        ui->loginErrorLabel_4->hide();
        globalCipherKey = enteredCipherKey;
        promptForPassword(enteredPassword);  // Validate with the actual entered password
    }
}

void MainWindow::on_copyCipherButton_2_clicked()
{
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(ui->cipherKeyText_2->text());
}

// ====================
// Private Slots
// ====================

void MainWindow::promptForPassword(const QString &password) {
    if (verifyPassword(password)) {
        myButtonsPage->show();
        this->hide();
    } else {
        ui->loginErrorLabel_4->setText("Incorrect Password.");
        ui->loginErrorLabel_4->show();
    }
}

void MainWindow::updatePassword(const QString &newPassword) {
    createPassword(newPassword, QString());  // Pass empty email since it's just an update

}
