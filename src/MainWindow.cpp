#include "MainWindow.hpp"
#include "views/MainWindowView.hpp"
#include "views/MenuBarView.hpp"
#include "views/ToolBarView.hpp"
#include "views/ScrollAreaView.hpp"

#include "controllers/MainWindowController.hpp"

#include <QCloseEvent>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    // views
    mainWindowView = new MainWindowView();
    mainWindowView->setupUi(this);
    menuBarView = new MenuBarView();
    menuBarView->setupUI();
    toolBarView = new ToolBarView();
    toolBarView->setupUI();
    setMenuBar(menuBarView);
    addToolBar(toolBarView);
    scrollAreaView = new ScrollAreaView();

    // controllers
    mainWindowController = new MainWindowController(this, mainWindowView);
    

}

void MainWindow::closeEvent(QCloseEvent* event) {
    mainWindowController->closeWindow(event);
}
