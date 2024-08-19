#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRandomGenerator>
#include "resetpassword.h"
#include <QDebug>  // Include for debugging

QString globalCipherKey;  // Temporary global variable for the cipher key

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
    QPalette errorPalette = ui->creationError_2->palette();  // Updated
    errorPalette.setColor(QPalette::WindowText, Qt::red);  // Set to red or any other color
    ui->creationError_2->setPalette(errorPalette);  // Updated
    ui->loginErrorLabel_4->setPalette(errorPalette);
    ui->creationError_2->hide();  // Updated
    ui->loginErrorLabel_4->hide();

    if (!passwordExists()){
        globalCipherKey = generateCipherKey();  // Generate the cipher key
        ui->cipherKeyText_2->setText(globalCipherKey);  // Updated
        ui->createPass->show();
    } else {
        ui->login->show();
    }
}

MainWindow::~MainWindow()
{
    globalCipherKey.clear();  // Clear the cipher key
    delete ui;
}

QString MainWindow::generateCipherKey() {
    return QString::number(QRandomGenerator::global()->generate64(), 16).toUpper();
}

// Updated slot function names based on the likely actual names of the objects in your .ui file
void MainWindow::on_createPassSubmitButton_2_clicked()
{
    QString firstPassEntry = ui->createPassEntry1_2->text();  // Updated
    QString secondPassEntry = ui->createPassEntry2_2->text();  // Updated
    QString email = ui->emailLabel_2->text();  // Updated

    int firstLen = firstPassEntry.length();
    int secondLen = secondPassEntry.length();

    if (firstLen < 8 || secondLen < 8){ // passwords aren't long enough
        ui->creationError_2->setText("ERROR: Passwords must have at least 8 characters.");  // Updated
        ui->creationError_2->show();  // Updated
    }
    else if (firstPassEntry != secondPassEntry){ // passwords don't match
        ui->creationError_2->setText("ERROR: Passwords Don't Match.");  // Updated
        ui->creationError_2->show();  // Updated
    } else {
        ui->creationError_2->hide();  // Updated
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
        cachedPasswordFilePath = dir.filePath("login.bin");
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
        ui->creationError_2->setText("Password Created Successfully");  // Updated
#ifdef QT_DEBUG
        qDebug() << "Password saved successfully.";  // Debug statement
#endif
    } else {
        ui->creationError_2->setText("Password Couldn't Save.");  // Updated
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

void MainWindow::on_loginButton_4_clicked()
{
    QString password = ui->passwordLoginEntry_4->text();
    QString enteredCipherKey = ui->cipherText->text();  // Capture the entered cipher key

    if (password.length() < 8){
        ui->loginErrorLabel_4->show();
        ui->loginErrorLabel_4->setText("Password Length Insufficient.");
    } else if (enteredCipherKey.isEmpty()) {
        ui->loginErrorLabel_4->show();
        ui->loginErrorLabel_4->setText("Cipher Key Required.");
    } else {
        ui->loginErrorLabel_4->hide();
        globalCipherKey = enteredCipherKey;  // Assign entered cipher key to global variable
        promptForPassword(password);
    }
}

void MainWindow::promptForPassword(const QString &password){
    if (verifyPassword(password)){
        myButtonsPage->show();
        this->hide();
    } else {
        ui->loginErrorLabel_4->setText("Incorrect Password.");
        ui->loginErrorLabel_4->show();
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

void MainWindow::on_copyCipherButton_2_clicked()
{
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(ui->cipherKeyText_2->text());  // Updated
}
