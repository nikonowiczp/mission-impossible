#include "gameview.h"
#include "utils.h"
#include "objects/monster.h"
#include "objects/human.h"
#include "objects/obstacle.h"
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

void GameView::StartGame(std::vector<std::shared_ptr<Positionable>> _positionables, int _width, int _height)
{
    std::srand(std::time(0));
    this->scene()->setSceneRect(0, 0, _width, _height);
    for (auto _positionable : _positionables )
    {
        if (dynamic_cast<Obstacle*>(_positionable.get()) != nullptr)
        {
            int i = std::rand() % _positionables.size();
            this->addObject(this->obstaclePaths[i], _positionable->GetId(),
                            _positionable->GetCoordinates().GetX(), _positionable->GetCoordinates().GetY(),
                            _positionable->Radius);
        }
        else if (dynamic_cast<Monster*>(_positionable.get()) != nullptr)
        {
            this->playerId = _positionable->GetId();
            this->addObject(this->monsterAssetPath, _positionable->GetId(),
                            _positionable->GetCoordinates().GetX(), _positionable->GetCoordinates().GetY(),
                            _positionable->Radius);
        }
        else if (dynamic_cast<Human*>(_positionable.get()) != nullptr)
        {
            this->addObject(this->humanAssetPath, _positionable->GetId(),
                            _positionable->GetCoordinates().GetX(), _positionable->GetCoordinates().GetY(),
                            _positionable->Radius);
        }
    }
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

void GameView::addObject(std::string _asset, int _id, int _x, int _y, int _r)
{
    CustomGraphicsItem* _item = new CustomGraphicsItem(_asset, _id, _x, _y, _r);
    this->scene()->addItem(_item);
    this->objects.insert(std::make_pair(_id, _item));
}




