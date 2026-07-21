#pragma once

#include <QString>


class MainWindow;
class MainWindowView;
class QCloseEvent;
class QPoint;
class QWidget;

class MainWindowController {
private:
    MainWindow* mainWindow;
    MainWindowView* mainWindowView;
    bool allowCloseWithoutConfirmation;

    bool getCloseWithoutConfirmationStatus() const;
public:
    MainWindowController(
        MainWindow* mainWindow,
        MainWindowView* mainWindowView
    );
    void updateStatusBarInView(const QPoint& position);
    void setWidgetToCentralWidget(QWidget* scrollAreaView);
    void selectCloseWithoutConfirmation();
    void unselectCloseWithoutConfirmation();
    void tryCloseWindow();
    void closeWindow(QCloseEvent* event);
};