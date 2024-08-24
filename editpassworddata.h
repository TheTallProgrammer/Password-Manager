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
    explicit editPasswordData(QWidget *parent = nullptr,  QString passId = "_passid",  QString dateStored = "_date",  QString password = "_password",  QString username = "_username",  QString thoughts = "_thoughts");
    ~editPasswordData();

signals:
    void overwriteData(const QString &passId, const QString &dateStored, const QString &password, const QString &username, const QString &thoughts);

private slots:

    void on_backButton_clicked();

    void on_saveButton_clicked();

private:
    Ui::editPasswordData *ui;
};

#endif // EDITPASSWORDDATA_H
