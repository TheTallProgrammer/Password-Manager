#ifndef PASSWORDINFO_H
#define PASSWORDINFO_H

#include <QDialog>

namespace Ui {
class passwordInfo;
}

class passwordInfo : public QDialog
{
    Q_OBJECT

public:
    explicit passwordInfo(QWidget *parent = nullptr, const QString &password = "");
    ~passwordInfo();

private slots:
    void on_copyButton_clicked();
    void on_acknowledgeButton_clicked();

private:
    Ui::passwordInfo *ui;
    QString m_password;
};

#endif // PASSWORDINFO_H
