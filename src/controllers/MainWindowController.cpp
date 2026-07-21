#include "controllers/MainWindowController.hpp"

#include "MainWindow.hpp"
#include "views/MainWindowView.hpp"
#include "views/ConfirmationDialogView.hpp"

#include <QCloseEvent>
#include <QPoint>
#include <QWidget>
#include <QString>

#include <iostream>

MainWindowController::MainWindowController(
        MainWindow* mainWindow,
        MainWindowView* mainWindowView
    ) : mainWindow(mainWindow),
        mainWindowView(mainWindowView),
        allowCloseWithoutConfirmation(true) {}

void MainWindowController::updateStatusBarInView(
        const QPoint& position
    ) {
    QString message = QString("Current mouse position: x - %1, y - %2")
                      .arg(position.x())
                      .arg(position.y());
    mainWindowView->updateStatusBar(message);
}

void MainWindowController::setWidgetToCentralWidget(
        QWidget* scrollAreaView
    ) {
    mainWindowView->setWidgetToCentralWidget(scrollAreaView);
}

void MainWindowController::selectCloseWithoutConfirmation() {
    allowCloseWithoutConfirmation = true;
}

void MainWindowController::unselectCloseWithoutConfirmation() {
    allowCloseWithoutConfirmation = false;
}

bool MainWindowController::getCloseWithoutConfirmationStatus() const {
    return allowCloseWithoutConfirmation;
}

void MainWindowController::tryCloseWindow() {
    mainWindow->close();
}

void MainWindowController::closeWindow(
        QCloseEvent* event
    ) {
    if(!getCloseWithoutConfirmationStatus()) {
        QString dialogTitle = "WARNING";
        QString dialogText = "Are you sure about exiting without saving?";
        ConfirmationDialogView confirmationDialog(
            mainWindow,
            dialogTitle,
            dialogText
        );
        if(!confirmationDialog.displayDialog()) {
            event->ignore();
        }
    }
}