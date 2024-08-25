#ifndef TRANSFERDATA_H
#define TRANSFERDATA_H

#include <QDialog>

namespace Ui {
class transferData;
}



class transferData : public QDialog
{
    Q_OBJECT

public:
    explicit transferData(QWidget *parent = nullptr);
    ~transferData();

signals:
    void backButtonPressed();

private slots:
    void on_backButton_clicked();

    void on_exportButton_clicked();

    void on_importButton_clicked();

private:
    Ui::transferData *ui;
};

#endif // TRANSFERDATA_H
