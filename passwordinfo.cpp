// ====================
// passwordinfo.cpp
// ====================

#include "passwordinfo.h"
#include "ui_passwordinfo.h"
#include <QClipboard>
#include <QApplication>

// ====================
// Constructor & Destructor
// ====================

passwordInfo::passwordInfo(QWidget *parent, const QString &password) :
    QDialog(parent),
    ui(new Ui::passwordInfo),
    m_password(password)
{
    ui->setupUi(this);
    setWindowTitle("Falkenberg's Password Manager");  // Set up window title
}

passwordInfo::~passwordInfo()
{
    delete ui;
}

// ====================
// Event Handlers
// ====================

void passwordInfo::on_copyButton_clicked()
{
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(m_password);  // Copy the password to the clipboard
}

void passwordInfo::on_acknowledgeButton_clicked()
{
    accept();  // Close the dialog
}
