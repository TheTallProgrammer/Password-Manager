#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QRandomGenerator>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , myButtonsPage(std::make_unique<passwordManagementButtons>())
{

    ui->setupUi(this);
    ui->createPass->hide();
    ui->login->hide();

    // UI Color stuff
    QPalette palette_creationErr = ui->creationError->palette();
    palette_creationErr.setColor(QPalette::WindowText, Qt::red);  // Set to red or any other color
    ui->creationError->setPalette(palette_creationErr);
    ui->creationError->hide();

    QPalette palette_loginErr = ui->creationError->palette();
    palette_loginErr.setColor(QPalette::WindowText, Qt::red);  // Set to red or any other color
    ui->loginErrorLabel->setPalette(palette_loginErr);
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
    if (firstPassEntry.length() < 8 || secondPassEntry.length() < 8){ // passwords aren't long enough
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


QString MainWindow::passwordFilePath(){
    // Find a suitable dir for the file to be saved in
    QString configDir = QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation);
    QDir dir(configDir);
    if (!dir.exists()){
        dir.mkpath(".");
    }
    return dir.filePath("pass.bin");
}

bool MainWindow::passwordExists(){
    QFile file(passwordFilePath());
    return file.exists();
}

void MainWindow::createPassword(QString firstPassEntry){
    QByteArray salt = generateSalt();
    QByteArray hashedPassword = hashPassword(firstPassEntry, salt);
    bool passSaved = saveToFile(hashedPassword, salt);
    (passSaved) ? ui->creationError->setText("Password Created Successfully") : ui->creationError->setText("Password Couldn't Save.");
    myButtonsPage->show(); // display the buttons page
    this->hide();
}

bool MainWindow::saveToFile(const QByteArray &hashedPassword, const QByteArray &salt) {
    QFile file(passwordFilePath());
    if (!file.open(QIODevice::WriteOnly)) {
        return false;
    }

    QDataStream out(&file);
    out << hashedPassword << salt;
    file.close();

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

void MainWindow::promptForPassword(QString password){
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
        return false;
    }
    QByteArray hashedPassword = hashPassword(password, salt);
    return hashedPassword == savedHashedPassword;
}

bool MainWindow::loadFromFile(QByteArray &hashedPassword, QByteArray &salt) {
    QFile file(passwordFilePath());
    if (!file.open(QIODevice::ReadOnly)) {
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
    QByteArray saltedPassword = password.toUtf8() + salt;
    QByteArray hashedPassword = QCryptographicHash::hash(saltedPassword, QCryptographicHash::Sha256);
    return hashedPassword;
}
// ---


