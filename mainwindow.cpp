#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <bits/stdc++.h>

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
    // todo header not visible
    std::vector<int> _games = this->logHandler->ReadGames();
    sort(_games.begin(), _games.end(), std::greater<int>());
    int _gameCounter = _games.size();
    ui->RankingTableWidget->setRowCount(_gameCounter);
    for ( int i = 0; i < _gameCounter; i++ )
    {
        ui->RankingTableWidget->setItem(i, 0, new QTableWidgetItem(QString((char)(i+1))));
        ui->RankingTableWidget->setItem(i, 0, new QTableWidgetItem(QString((char)_games[i])));
    }
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


void MainWindow::on_GameOverBackButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

