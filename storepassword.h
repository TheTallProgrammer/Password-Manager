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

private:
    Ui::storePassword *ui;
};

#endif // STOREPASSWORD_H
