#ifndef PASSWORDMANAGEMENTBUTTONS_H
#define PASSWORDMANAGEMENTBUTTONS_H

#include <QDialog>

namespace Ui {
class passwordManagementButtons;
}

class passwordManagementButtons : public QDialog
{
    Q_OBJECT

public:
    explicit passwordManagementButtons(QWidget *parent = nullptr);
    ~passwordManagementButtons();

private slots:
    void on_genPass_clicked();

private:
    Ui::passwordManagementButtons *ui;
};

#endif // PASSWORDMANAGEMENTBUTTONS_H
