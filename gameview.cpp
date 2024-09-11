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
    this->objects.clear();
    this->scene()->clear();
    this->keysState = 0;
}

void GameView::StartGame(std::vector<std::shared_ptr<Positionable>> _positionables, Monster* _player, int _width, int _height)
{
    std::srand(std::time(0));
    this->scene()->setSceneRect(0, 0, _width, _height);
    for ( auto _positionable : _positionables )
    {
        this->addObject(_positionable);
    }
    this->addMonster(_player);
    this->centerOn(_player->GetCoordinates().GetX(), _player->GetCoordinates().GetX());
}

void GameView::DoTick(std::vector<std::shared_ptr<Positionable>> _positionables, Monster* _player)
{
    for ( auto _positionable : _positionables )
    {
        auto _objectsIter = this->objects.find(_positionable->GetId());
        if (_objectsIter != this->objects.end())
        {
            _objectsIter->second->Move(_positionable->GetCoordinates().GetX(), _positionable->GetCoordinates().GetY());
        }
        else
        {
            this->addObject(_positionable);
        }
    }
    this->objects[_player->GetId()]->Move(_player->GetCoordinates().GetX(), _player->GetCoordinates().GetX());
    this->centerOn(_player->GetCoordinates().GetX(), _player->GetCoordinates().GetX());
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

void GameView::addObject(std::shared_ptr<Positionable> _positionable)
{
    if (dynamic_cast<Obstacle*>(_positionable.get()) != nullptr)
    {
        int i = std::rand() % this->obstaclePaths.size();
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

void GameView::addObject(std::string _asset, int _id, int _x, int _y, int _r)
{
    CustomGraphicsItem* _item = new CustomGraphicsItem(_asset, _id, _x, _y, _r);
    this->scene()->addItem(_item);
    this->objects.insert(std::make_pair(_id, _item));
}

void GameView::addMonster(Monster *_monster)
{
    this->playerId = _monster->GetId();
    this->addObject(this->monsterAssetPath, _monster->GetId(),
                    _monster->GetCoordinates().GetX(), _monster->GetCoordinates().GetY(),
                    _monster->Radius);
}
