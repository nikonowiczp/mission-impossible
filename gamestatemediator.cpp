#include "gamestatemediator.h"
#include "objects/movable.h"
#include "objects/commandcenter.h"
#include "utils.h"

GameStateMediator::GameStateMediator(std::vector<std::shared_ptr<Positionable>> objects)
{
    this->gameObjects = std::move(objects);
}

void GameStateMediator::DoTick(int _userInput)
{
    tick++;
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
