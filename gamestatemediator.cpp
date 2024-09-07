#include "gamestatemediator.h"
#include "objects/baseobject.h"
#include "utils.h"

GameStateMediator::GameStateMediator(std::vector<std::shared_ptr<Positionable>> objects)
{
    this->gameObjects = std::move(objects);
}

void GameStateMediator::DoTick(int _userInput)
{
    tick++;
}

std::vector<std::shared_ptr<Positionable>> GameStateMediator::getVisibleObjects(std::shared_ptr<Positionable> _object)
{
    std::vector<std::shared_ptr<Positionable>> _visibleObjects = {};
    for (auto _gameObject : this->gameObjects )
    {
        if (_object != _gameObject &&
                Utils::CalculateLength(_object, _gameObject) < _object->GetRange())
        {
            _visibleObjects.push_back(_gameObject);
        }
    }
    return _visibleObjects;
}
