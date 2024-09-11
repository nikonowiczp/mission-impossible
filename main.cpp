#include "mainwindow.h"

#include <QApplication>
#include "csvloghandler.h"
#include "gamemanager.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w(std::make_unique<GameManager>(), std::make_unique<CSVLogHandler>());
    w.show();
    auto manager = std::make_unique<GameManager>();
    manager->PrepareHard();
    for(int i =0; i<10;i++){
        manager->DoTick(0);
    }
    return a.exec();
}
