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
