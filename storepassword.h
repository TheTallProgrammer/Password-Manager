// storepassword.h
#ifndef STOREPASSWORD_H
#define STOREPASSWORD_H

#include <QDialog>

namespace Ui {
class storePassword;
}

class storePassword : public QDialog
{
    Q_OBJECT

public:
    explicit storePassword(QWidget *parent = nullptr);
    ~storePassword();

signals:
    void requestGenPassword();  // Signal to request generating a password
    void emitBackClicked();

private slots:
    void on_backButton_clicked();
    void on_genPassButton_clicked();

private:
    Ui::storePassword *ui;
};

#endif // STOREPASSWORD_H
