#ifndef EDITPASSWORDDATA_H
#define EDITPASSWORDDATA_H

#include <QDialog>

namespace Ui {
class editPasswordData;
}

class editPasswordData : public QDialog
{
    Q_OBJECT

public:
    explicit editPasswordData(QWidget *parent = nullptr);
    ~editPasswordData();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::editPasswordData *ui;
};

#endif // EDITPASSWORDDATA_H
