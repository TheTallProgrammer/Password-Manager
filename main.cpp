#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.setWindowTitle("Falkenberg's Password Manager");
    w.setWindowIcon(QIcon("../../icon.png"));
    w.show();
    return a.exec();
}
