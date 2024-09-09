#include "gameview.h"

GameView::GameView(QWidget *_parent)
{
    QGraphicsScene *_scene = new QGraphicsScene(this);
    setScene(_scene);
    _scene->setSceneRect(0, 0, 2000, 2000);
    _scene->setBackgroundBrush(QBrush(QColor(128, 128, 128)));

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

void GameView::ClearGame()
{
    this->scene()->clear();
}

void GameView::StartGame()
{
    this->scene()->setSceneRect(0, 0, 2000, 2000);
    this->centerOn(this->scene()->sceneRect().center());
}


