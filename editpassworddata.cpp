#include "editpassworddata.h"
#include "ui_editpassworddata.h"

// For this, it'll need the password data from the entry in the table passed into this object instance when the edit button is pressed (since it's already decrypted). It'll fill the fields, the user will do what they want. If they hit back, then the instance is just deleted and nothing is returned. If they hit save, they return or emit the new text field data back to the table entry they clicked to edit, and it overwrtites the existing data in that entry with the new data (assuming they changed something, if they just hit save and they didn't change anything, then it would just be the same since the passed in data fills the text boxes anyway)

editPasswordData::editPasswordData(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::editPasswordData)
{
    ui->setupUi(this);
}

editPasswordData::~editPasswordData()
{
    delete ui;
}

void editPasswordData::on_pushButton_clicked()
{

}


void editPasswordData::on_pushButton_2_clicked()
{

}

