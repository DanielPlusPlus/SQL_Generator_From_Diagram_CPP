#include <QApplication>
#include <QIcon>


#include "MainWindow.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    app.setWindowIcon(QIcon("icons/icon.ico"));

    // MainWindow window(&app);
    MainWindow window;
    window.show();

    return app.exec();
}