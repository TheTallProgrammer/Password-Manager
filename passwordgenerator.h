#ifndef PASSWORDGENERATOR_H
#define PASSWORDGENERATOR_H

#include <QDialog>
#include <vector>
#include <random>
#include <QCheckBox>
#include <QString>
#include <QWidget>
#include <QClipboard>
#include <QApplication>
#include <QCloseEvent>


namespace Ui {
class PasswordGenerator;
}

class PasswordGenerator : public QDialog
{
    Q_OBJECT

public:
    explicit PasswordGenerator(QWidget *parent = nullptr);
    ~PasswordGenerator();
    char* createPassword(int len, int comp);
    void updateSymbols(bool checked, char symbol);

private slots:
    void on_PassLengthSlider_sliderMoved(int position);
    void on_PassCompSlider_sliderMoved(int position);
    void on_GenPass_clicked();
    void on_CopyButton_clicked();

    void on_checkBox_1_stateChanged(int arg1);

    void on_checkBox_2_stateChanged(int arg1);

    void on_checkBox_3_stateChanged(int arg1);

    void on_checkBox_4_stateChanged(int arg1);

    void on_checkBox_5_stateChanged(int arg1);

    void on_checkBox_6_stateChanged(int arg1);

    void on_checkBox_7_stateChanged(int arg1);

    void on_checkBox_8_stateChanged(int arg1);

    void on_checkBox_9_stateChanged(int arg1);

    void on_checkBox_10_stateChanged(int arg1);

    void on_checkBox_11_stateChanged(int arg1);

    void on_checkBox_12_stateChanged(int arg1);

    void on_checkBox_13_stateChanged(int arg1);


    void on_checkBox_14_stateChanged(int arg1);

    void on_checkBox_15_stateChanged(int arg1);

    void on_checkBox_16_stateChanged(int arg1);

    void on_checkBox_17_stateChanged(int arg1);

    void on_checkBox_18_stateChanged(int arg1);

    void on_checkBox_19_stateChanged(int arg1);

    void on_checkBox_20_stateChanged(int arg1);

    void on_checkBox_21_stateChanged(int arg1);

    void on_checkBox_22_stateChanged(int arg1);

    void on_checkBox_23_stateChanged(int arg1);

    void on_checkBox_24_stateChanged(int arg1);

    void on_checkBox_25_stateChanged(int arg1);

    void on_checkBox_26_stateChanged(int arg1);

    void on_checkBox_27_stateChanged(int arg1);

    void on_checkBox_28_stateChanged(int arg1);

    void on_exitButton_clicked();

private:
    Ui::PasswordGenerator *ui;
    int *_passLength;
    int *_passComp;
    std::vector<char> *_letters;
    std::vector<char> *_numbers;
    std::vector<char> *_symbols;
    void closeEvent(QCloseEvent *event);
};

#endif // PASSWORDGENERATOR_H
