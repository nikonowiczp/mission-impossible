#include "gamestatemediator.h"
#include "objects/commandcenter.h"
#include "objects/movable.h"
#include "objects/monster.h"
#include "utils.h"

GameStateMediator::GameStateMediator(std::unique_ptr<GameOptions> options)
{
    this->options = std::move(options);
    this->commandCenter = std::make_unique<CommandCenter>(std::shared_ptr<GameStateMediator>(this));
}

void GameStateMediator::DoTick(int _userInput)
{
    tick++;
    //do monster move
    this->monster->OnGameTick(_userInput);
    this->commandCenter->OnGameTick();
    for(auto a : gameObjects){
        a->OnGameTick();
    }

}

std::vector<std::shared_ptr<Positionable>> GameStateMediator::getVisibleObjects(std::shared_ptr<Movable> _object)
{
    std::vector<std::shared_ptr<Positionable>> _visibleObjects = {};
    for (auto _gameObject : this->gameObjects )
    {
        if (_object != _gameObject &&
                Utils::CalculateLength(std::dynamic_pointer_cast<Positionable>(_object), _gameObject) < _object->GetRange())
        {
            _visibleObjects.push_back(_gameObject);
        }
    }
    return _visibleObjects;
}

std::vector<std::shared_ptr<Positionable> > GameStateMediator::getPeople()
{
    //TODO
}

std::vector<std::shared_ptr<Positionable> > GameStateMediator::getAll()
{
    return this->gameObjects;
}

void GameStateMediator::SetObjects(std::vector<std::shared_ptr<Positionable> > objects)
{
    this->gameObjects = objects;
}

