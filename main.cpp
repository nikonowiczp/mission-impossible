#include "mainwindow.h"

#include <QApplication>
#include "csvloghandler.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w(std::unique_ptr<ILogHandler>(new CSVLogHandler()));
    w.show();
    return a.exec();
}
