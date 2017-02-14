#include "MainWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //Fenêtre principale
    MainWindow ctWindow;

    return app.exec();
}
