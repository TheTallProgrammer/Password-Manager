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

private:
    Ui::transferData *ui;
};

#endif // TRANSFERDATA_H
