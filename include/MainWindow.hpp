#pragma once

#include <QMainWindow>


class MainWindowView;
class MenuBarView;
class ToolBarView;
class ScrollAreaView;
class MainWindowController;

class MainWindow : public QMainWindow {
    Q_OBJECT
private:
    MainWindowView* mainWindowView;
    MenuBarView* menuBarView;
    ToolBarView* toolBarView;
    ScrollAreaView* scrollAreaView;
    MainWindowController* mainWindowController;
protected:
    void closeEvent(QCloseEvent* event) override;
public:
    explicit MainWindow(QWidget* parent = nullptr);
};