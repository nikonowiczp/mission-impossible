#include "mainwindow.h"
#include "objects/positionable.h"

#include "qtimer.h"
#include "./ui_mainwindow.h"

#include <memory>
#include <bits/stdc++.h>

MainWindow::MainWindow(std::unique_ptr<GameManager> _gameManager, std::unique_ptr<ILogHandler> _handler, QWidget *_parent)
    : QMainWindow(_parent)
    , ui(new Ui::MainWindow)
{
    this->gameManager = std::move(_gameManager);
    this->logHandler = std::move(_handler);
    ui->setupUi(this);
    this->gameView = new GameView();
    ui->GamePage->layout()->addWidget(this->gameView);
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

void MainWindow::on_EasyButton_clicked()
{
    this->startGame();
}


void MainWindow::on_MediumButton_clicked()
{
    this->startGame();
}


void MainWindow::on_HardButton_clicked()
{
    this->startGame();
}

void MainWindow::startGame()
{
    // TODO get objects from game manager
    std::vector<std::shared_ptr<Positionable>> _gameObjects = {};
    this->gameView->StartGame(_gameObjects);
    this->timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(DoTick()));
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::gameOver()
{

}

void MainWindow::DoTick()
{
    // TODO get objects from game manager
    std::vector<std::shared_ptr<Positionable>> _gameObjects = {};
    this->gameView->Move(_gameObjects);
    // TODO do tick in game manager
}

