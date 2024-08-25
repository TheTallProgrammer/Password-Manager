#include "mainwindow.h"

#include <QApplication>
#include "passwordmanagementbuttons.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    passwordManagementButtons pmb;

    // Connect the updateTheme signal to the handleUpdateTheme slot
    QObject::connect(&pmb, &passwordManagementButtons::updateTheme,
                     &w, &MainWindow::handleUpdateTheme);


    w.show();
    return a.exec();
}
