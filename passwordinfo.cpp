// passwordinfo.cpp
#include "passwordinfo.h"
#include "ui_passwordinfo.h"
#include <QClipboard>
#include <QApplication>

passwordInfo::passwordInfo(QWidget *parent, const QString &password) :
    QDialog(parent),
    ui(new Ui::passwordInfo),
    m_password(password)
{
    ui->setupUi(this);
    // Set up any UI elements or text here if needed
}

passwordInfo::~passwordInfo()
{
    delete ui;
}

void passwordInfo::on_copyButton_clicked()
{
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(m_password);
}

void passwordInfo::on_acknowledgeButton_clicked()
{
    accept();  // Close the dialog
}
