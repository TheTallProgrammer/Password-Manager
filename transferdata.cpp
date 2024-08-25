#include "transferdata.h"
#include "ui_transferdata.h"

transferData::transferData(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::transferData)
{
    ui->setupUi(this);
}

transferData::~transferData()
{
    delete ui;
}

void transferData::on_backButton_clicked()
{
    emit backButtonPressed();
}


void transferData::on_exportButton_clicked()
{

}


void transferData::on_importButton_clicked()
{

}

