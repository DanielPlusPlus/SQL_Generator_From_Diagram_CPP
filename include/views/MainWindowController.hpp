#pragma once

#include <QObject>
#include <QString>


class QGridLayout;
class QHBoxLayout;
class QStatusBar;
class QWidget;
class QMainWindow;

class MainWindowView : public QObject {
    Q_OBJECT
private:
    void retranslateUi(QMainWindow* mainWindow);
private:
    QWidget* centralWidget;
    QGridLayout* gridLayout;
    QHBoxLayout* horizontalLayout;
    QStatusBar* statusBar;
public:
    explicit MainWindowView(QObject* parent = nullptr);
    void setupUi(QMainWindow* parentWindow);
    void setWidgetToCentralWidget(QWidget* widget);
    void updateStatusBar(const QString& message);
};