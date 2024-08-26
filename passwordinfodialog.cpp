// passwordinfodialog.cpp
#include "passwordinfodialog.h"
#include "ui_passwordinfo.h".h"
#include <QClipboard>
#include <QApplication>

PasswordInfoDialog::PasswordInfoDialog(QWidget *parent, const QString &password) :
    QDialog(parent),
    ui(new Ui::passwordInfo),
    m_password(password)
{
    ui->setupUi(this);
}

PasswordInfoDialog::~PasswordInfoDialog()
{
    delete ui;
}

void PasswordInfoDialog::on_copyButton_clicked()
{
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(m_password);
}

void PasswordInfoDialog::on_acknowledgeButton_clicked()
{
    accept();  // Close the dialog
}
