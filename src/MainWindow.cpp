#include "MainWindow.hpp"
#include "views/MainWindowController.hpp"

#include <QCloseEvent>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    // views
    mainWindowView = new MainWindowView();
    mainWindowView->setupUi(this);

}

// void MainWindow::closeEvent(QCloseEvent *event) {
//     QMainWindow::closeEvent(event);
// }
