#include "passwordgenerator.h"
#include "ui_passwordgenerator.h"
#include <QClipboard>
#include <QCloseEvent>
#include <random>

// =====================
// Constructor & Destructor
// =====================

PasswordGenerator::PasswordGenerator(QWidget *parent)
    : QDialog(nullptr)
    , ui(new Ui::PasswordGenerator)
{
    ui->setupUi(this);
    ui->excludeChar->hide();

    _passLength = new int(1);
    _passComp = new int(1);

    _letters = new std::vector<char>({
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
    });

    _numbers = new std::vector<char>({'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'});

    _symbols = new std::vector<char>({
        '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '=', '+',
        '[', ']', '{', '}', ';', ':', '\'', '\"', '<', '>', ',', '.', '?', '/'
    });

    ui->PassLength->setText(QString::number(*_passLength));
    ui->PassComp->setText(QString::number(*_passComp));
}

PasswordGenerator::~PasswordGenerator()
{
    // Free the allocated memory upon program close
    delete _passLength;
    delete _passComp;
    delete _letters;
    delete _numbers;
    delete _symbols;
    delete ui;
}

// =====================
// Event Handlers
// =====================

void PasswordGenerator::closeEvent(QCloseEvent *event) {
    qDebug() << "PasswordGenerator is closing";
    event->accept();  // Explicitly accept the close event to avoid any potential issues
}

void PasswordGenerator::on_PassLengthSlider_sliderMoved(int position)
{
    *_passLength = position;
    ui->PassLength->setText(QString::number(position));
}

void PasswordGenerator::on_PassCompSlider_sliderMoved(int position)
{
    *_passComp = position;
    ui->PassComp->setText(QString::number(position));

    // Show or hide the excludeChar checkbox based on password complexity
    if(position == 3) {
        ui->excludeChar->show();
    } else {
        ui->excludeChar->hide();
    }
}

void PasswordGenerator::on_GenPass_clicked()
{
    // Generate a new password and display it in the GeneratedPassLabel
    char* password = createPassword(*_passLength, *_passComp);
    ui->GeneratedPassLabel->setText(password);
    delete[] password;  // Free the allocated memory for the password
}

void PasswordGenerator::on_CopyButton_clicked()
{
    QClipboard *clipboard = QApplication::clipboard();
    QString textToCopy = ui->GeneratedPassLabel->text();
    clipboard->setText(textToCopy);  // Copy the generated password to the clipboard
}

void PasswordGenerator::on_exitButton_clicked()
{
    this->hide();  // Hide the dialog instead of closing it completely
}

// =====================
// Password Generation Logic
// =====================

char* PasswordGenerator::createPassword(int len, int comp) {
    // Dynamically allocate memory for a char array of the given size
    char* array = new char[len + 1];  // +1 for the null terminator
    std::random_device rd;
    std::mt19937 gen(rd());

    // Define the distribution and sources based on the complexity
    std::uniform_int_distribution<size_t> distr;

    switch(comp) {
    case 1: // Letters only
        distr = std::uniform_int_distribution<size_t>(0, _letters->size() - 1);
        break;
    case 2: // Letters and numbers
        distr = std::uniform_int_distribution<size_t>(0, _letters->size() + _numbers->size() - 1);
        break;
    case 3: // Letters, numbers, and symbols
        distr = std::uniform_int_distribution<size_t>(0, _letters->size() + _numbers->size() + _symbols->size() - 1);
        break;
    default:
        throw std::invalid_argument("Invalid complexity level.");
    }

    for(int i = 0; i < len; ++i) {
        size_t randInt = distr(gen);
        if (comp == 1) {
            array[i] = _letters->at(randInt);
        } else if (comp == 2) {
            if (randInt < _letters->size()) {
                array[i] = _letters->at(randInt);
            } else {
                array[i] = _numbers->at(randInt - _letters->size());
            }
        } else if (comp == 3) {
            if (randInt < _letters->size()) {
                array[i] = _letters->at(randInt);
            } else if (randInt < _letters->size() + _numbers->size()) {
                array[i] = _numbers->at(randInt - _letters->size());
            } else {
                array[i] = _symbols->at(randInt - _letters->size() - _numbers->size());
            }
        }
    }

    array[len] = '\0';  // Null-terminate the string
    return array;  // Return the pointer to the allocated array
}

// =====================
// Checkbox Handlers
// =====================

void PasswordGenerator::updateSymbols(bool checked, char symbol)
{
    if (checked) {
        auto it = std::remove(_symbols->begin(), _symbols->end(), symbol);
        if (it != _symbols->end()) {
            _symbols->erase(it, _symbols->end());  // Remove symbol if checkbox is checked
        }
    } else {
        if (std::find(_symbols->begin(), _symbols->end(), symbol) == _symbols->end()) {
            _symbols->push_back(symbol);  // Add symbol back if checkbox is unchecked
        }
    }
}

void PasswordGenerator::on_checkBox_1_stateChanged(int arg1)
{
    updateSymbols(arg1 == Qt::Checked, '&');
}
void PasswordGenerator::on_checkBox_2_stateChanged(int arg1)
{
    updateSymbols(arg1 == Qt::Checked, '@');
}
void PasswordGenerator::on_checkBox_3_stateChanged(int arg1)
{
    updateSymbols(arg1 == Qt::Checked, '{');
    updateSymbols(arg1 == Qt::Checked, '}');
}
void PasswordGenerator::on_checkBox_4_stateChanged(int arg1)
{
    updateSymbols(arg1 == Qt::Checked, '#');
}
void PasswordGenerator::on_checkBox_5_stateChanged(int arg1)
{
    updateSymbols(arg1 == Qt::Checked, '[');
    updateSymbols(arg1 == Qt::Checked, ']');
}
void PasswordGenerator::on_checkBox_6_stateChanged(int arg1)
{
    updateSymbols(arg1 == Qt::Checked, '=');
}
void PasswordGenerator::on_checkBox_7_stateChanged(int arg1)
{
    updateSymbols(arg1 == Qt::Checked, '(');
    updateSymbols(arg1 == Qt::Checked, ')');
}
void PasswordGenerator::on_checkBox_8_stateChanged(int arg1)
{
    updateSymbols(arg1 == Qt::Checked, '-');
}
void PasswordGenerator::on_checkBox_9_stateChanged(int arg1)
{
    updateSymbols(arg1 == Qt::Checked, '?');
}
void PasswordGenerator::on_checkBox_10_stateChanged(int arg1)
{
    updateSymbols(arg1 == Qt::Checked, '`');
}
void PasswordGenerator::on_checkBox_11_stateChanged(int arg1)
{
    updateSymbols(arg1 == Qt::Checked, '\\');
}
void PasswordGenerator::on_checkBox_12_stateChanged(int arg1)
{
    updateSymbols(arg1 == Qt::Checked, '/');
}
void PasswordGenerator::on_checkBox_13_stateChanged(int arg1)
{
    updateSymbols(arg1 == Qt::Checked, '|');
}
void PasswordGenerator::on_checkBox_14_stateChanged(int arg1)
{
    updateSymbols(arg1 == Qt::Checked, '*');
}
void PasswordGenerator::on_checkBox_15_stateChanged(int arg1)
{
    updateSymbols(arg1 == Qt::Checked, '"');
}
void PasswordGenerator::on_checkBox_16_stateChanged(int arg1)
{
    updateSymbols(arg1 == Qt::Checked, ':');
}
void PasswordGenerator::on_checkBox_17_stateChanged(int arg1)
{
    updateSymbols(arg1 == Qt::Checked, ';');
}
void PasswordGenerator::on_checkBox_18_stateChanged(int arg1)
{
    updateSymbols(arg1 == Qt::Checked, '<');
    updateSymbols(arg1 == Qt::Checked, '>');
}
void PasswordGenerator::on_checkBox_19_stateChanged(int arg1)
{
    updateSymbols(arg1 == Qt::Checked, '~');
}
void PasswordGenerator::on_checkBox_20_stateChanged(int arg1)
{
    updateSymbols(arg1 == Qt::Checked, '$');
}
void PasswordGenerator::on_checkBox_21_stateChanged(int arg1)
{
    updateSymbols(arg1 == Qt::Checked, '!');
}
void PasswordGenerator::on_checkBox_22_stateChanged(int arg1)
{
    updateSymbols(arg1 == Qt::Checked, '%');
}
void PasswordGenerator::on_checkBox_23_stateChanged(int arg1)
{
    updateSymbols(arg1 == Qt::Checked, '^');
}
void PasswordGenerator::on_checkBox_24_stateChanged(int arg1)
{
    updateSymbols(arg1 == Qt::Checked, '_');
}
void PasswordGenerator::on_checkBox_25_stateChanged(int arg1)
{
    updateSymbols(arg1 == Qt::Checked, '+');
}
void PasswordGenerator::on_checkBox_26_stateChanged(int arg1)
{
    updateSymbols(arg1 == Qt::Checked, '\'');
}
void PasswordGenerator::on_checkBox_27_stateChanged(int arg1)
{
    updateSymbols(arg1 == Qt::Checked, ',');
}
void PasswordGenerator::on_checkBox_28_stateChanged(int arg1)
{
    updateSymbols(arg1 == Qt::Checked, '.');
}
