#include "views/MainWindowView.hpp"

#include <QMainWindow>
#include <QWidget>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QStatusBar>
#include <QCoreApplication>


MainWindowView::MainWindowView(
        QObject* parent
    ) : QObject(parent),
        centralWidget(nullptr),
        gridLayout(nullptr),
        horizontalLayout(nullptr),
        statusBar(nullptr) {}

void MainWindowView::setupUi(QMainWindow* parentWindow) {
    if(parentWindow->objectName().isEmpty()) {
        parentWindow->setObjectName("MainWindow");
    }
    parentWindow->resize(800, 600);
    centralWidget = new QWidget(parentWindow);
    gridLayout = new QGridLayout(centralWidget);
    horizontalLayout = new QHBoxLayout();
    gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);
    parentWindow->setCentralWidget(centralWidget);
    statusBar = new QStatusBar(parentWindow);
    parentWindow->setStatusBar(statusBar);
    retranslateUi(parentWindow);
}

void MainWindowView::retranslateUi(QMainWindow* mainWindow) {
    mainWindow->setWindowTitle(
        QCoreApplication::translate(
            "MainWindow",
            "SQL Generator From Diagram"
        )
    );
}

void MainWindowView::setWidgetToCentralWidget(QWidget* widget) {
    horizontalLayout->addWidget(widget);
}

void MainWindowView::updateStatusBar(const QString& message) {
    statusBar->showMessage(message);
}