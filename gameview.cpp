#include "gameview.h"
#include "utils.h"
#include <QDebug>

GameView::GameView(QWidget *_parent)
{
    QGraphicsScene *_scene = new QGraphicsScene(this);
    setScene(_scene);
    _scene->setSceneRect(0, 0, 2000, 2000);
    _scene->setBackgroundBrush(QBrush(QColor(128, 128, 128)));

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setFocusPolicy(Qt::StrongFocus);
}

void GameView::ClearGame()
{
    this->scene()->clear();
    this->keysState = 0;
}

void GameView::StartGame(std::vector<std::shared_ptr<Positionable>> _gameObjects, int _width, int _height)
{
    this->scene()->setSceneRect(0, 0, _width, _height);
    this->centerOn(this->scene()->sceneRect().center());
}

void GameView::Move(std::vector<std::shared_ptr<Positionable> >)
{

}

int GameView::GetKeysState()
{
    return this->keysState;
}

void GameView::keyPressEvent(QKeyEvent *_event)
{
    if (_event->key() == Qt::Key_Escape)
    {
        emit EscPressed();
    }
    else
    {
        auto _keysMap = Utils::GetKeysMap();
        auto _keysIter = _keysMap.find(_event->key());
        if (_keysIter != _keysMap.end())
        {
            this->keysState |= _keysIter->second;
        }
    }
    QGraphicsView::keyPressEvent(_event);
}

void GameView::keyReleaseEvent(QKeyEvent *_event)
{
    auto _keysMap = Utils::GetKeysMap();
    auto _keysIter = _keysMap.find(_event->key());
    if (_keysIter != _keysMap.end())
    {
        this->keysState &= ~_keysIter->second;
    }
}




