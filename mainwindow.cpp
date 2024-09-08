#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
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

