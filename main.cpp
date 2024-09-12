#include "mainwindow.h"

#include <QApplication>
#include "loghandler.h"
#include "gamemanager.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w(std::make_unique<GameManager>(), std::make_unique<LogHandler>());
    w.show();
    return a.exec();
}
