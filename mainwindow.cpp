#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(std::unique_ptr<ILogHandler> _handler, QWidget *_parent)
    : QMainWindow(_parent)
    , ui(new Ui::MainWindow)
{
    this->logHandler = std::move(_handler);
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_StartButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_RankingButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_ExitButton_clicked()
{
    close();
}


void MainWindow::on_DifficultiesBackButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_RankingBackButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

