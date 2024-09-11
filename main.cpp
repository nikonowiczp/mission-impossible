#include "mainwindow.h"

#include <QApplication>
#include "csvloghandler.h"
#include "gamemanager.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w(std::make_unique<GameManager>(), std::make_unique<CSVLogHandler>());
    w.show();
    return a.exec();
}
