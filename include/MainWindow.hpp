#pragma once

#include <QMainWindow>


class MainWindowView;
class MainWindowController;

class MainWindow : public QMainWindow {
    Q_OBJECT
private:
    MainWindowView *mainWindowView;
    MainWindowController *mainWindowController;
// protected:
//     void closeEvent(QCloseEvent *event) override;
public:
    explicit MainWindow(QWidget *parent = nullptr);
};