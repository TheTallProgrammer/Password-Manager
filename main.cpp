#include "mainwindow.h"
#include <QApplication>

// ====================
// Main Function
// ====================
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);  // Initialize the application
    MainWindow w;  // Create the main window

    w.setWindowTitle("Falkenberg's Password Manager");  // Set window title
    w.setWindowIcon(QIcon("../../icon.png"));  // Set window icon
    w.show();  // Show the main window

    return a.exec();  // Execute the application event loop
}
