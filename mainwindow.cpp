#include "mainwindow.h"
#include "objects/positionable.h"

#include <QDebug>
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
    ui->GamePausedWidget->setParent(this->gameView);
    ui->GamePausedWidget->raise();
    ui->GamePausedWidget->setVisible(false);
    connect(this->gameView, &GameView::EscPressed, this, &MainWindow::OnEscDuringGame);
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
    connect(timer, &QTimer::timeout, this, &MainWindow::DoTick);
    ui->stackedWidget->setCurrentIndex(4);
    this->timer->start(timeoutDuration);
}

void MainWindow::gameOver()
{
    timer->stop();
    delete timer;
    //TODO add counting the points
    this->logHandler->SaveGame(this->timeoutCounter);
    this->timeoutCounter = 0;
    ui->GamePausedWidget->setVisible(false);
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::pause()
{
    ui->GamePausedWidget->setGeometry(ui->GamePage->rect());
    ui->GamePausedWidget->setVisible(true);
    this->timer->stop();
}

void MainWindow::resume()
{
    this->timer->start(timeoutDuration);
    ui->GamePausedWidget->setVisible(false);
}

void MainWindow::resizeEvent(QResizeEvent *_event)
{
    QMainWindow::resizeEvent(_event);
    if (ui->GamePausedWidget->isVisible())
    {
        ui->GamePausedWidget->setGeometry(ui->GamePage->rect());
    }
}

void MainWindow::DoTick()
{
    // TODO get objects from game manager
    timeoutCounter++;
    std::vector<std::shared_ptr<Positionable>> _gameObjects = {};
    this->gameView->Move(_gameObjects);
    // TODO do tick in game manager
}

void MainWindow::OnEscDuringGame()
{
    if (ui->GamePausedWidget->isVisible())
    {
        this->resume();
    }
    else
    {
        this->pause();
    }
}


void MainWindow::on_GameExitButton_clicked()
{
    this->gameOver();
}


void MainWindow::on_ResumeButton_clicked()
{
    this->resume();
}


void MainWindow::on_RestartButton_clicked()
{
    this->startGame();
}

