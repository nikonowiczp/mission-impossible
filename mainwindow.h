#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "iloghandler.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(std::unique_ptr<ILogHandler>, QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_StartButton_clicked();

    void on_RankingButton_clicked();

    void on_ExitButton_clicked();

    void on_DifficultiesBackButton_clicked();

    void on_RankingBackButton_clicked();

    void on_GameOverBackButton_clicked();

private:
    Ui::MainWindow *ui;
    std::unique_ptr<ILogHandler> logHandler;
};
#endif // MAINWINDOW_H
