#include "gamestatemediator.h"
#include "objects/commandcenter.h"
#include "objects/movable.h"
#include "objects/monster.h"
#include "utils.h"

GameStateMediator::GameStateMediator(std::unique_ptr<GameOptions> options)
{
    this->options = std::move(options);
}

void GameStateMediator::DoTick(int _userInput)
{
    assert(monster.get() != nullptr);
    assert(commandCenter.get() != nullptr);
    tick++;
    //do monster move
    this->monster->OnGameTick(_userInput);
    this->commandCenter->OnGameTick();
    for(const auto& a : gameObjects){
        a->OnGameTick();
    }

}

std::vector<Positionable*> GameStateMediator::getVisibleObjects(Movable* _object)
{
    std::vector<Positionable*> _visibleObjects = {};
    for (const auto &_gameObject : this->gameObjects )
    {
        if (_object->GetId() != _gameObject->GetId() &&
            Utils::CalculateLength(_object, _gameObject.get()) < _object->GetRange())
        {
            _visibleObjects.push_back(_gameObject.get());
        }
    }
    return _visibleObjects;
}

std::vector<Positionable *> GameStateMediator::getPeople()
{
    //TODO
}

std::vector<Positionable *> GameStateMediator::getAll()
{
    std::vector<Positionable*> rawPtrs;
    rawPtrs.reserve(gameObjects.size());

    std::transform(gameObjects.begin(), gameObjects.end(), std::back_inserter(rawPtrs),
                   [](const std::unique_ptr<Positionable>& ptr) {
                       return ptr.get();
                   });
    return rawPtrs;
}

void GameStateMediator::SetObjects(std::vector<std::unique_ptr<Positionable> > objects)
{
    this->gameObjects = std::move(objects);
}

void GameStateMediator::SetMonster(std::unique_ptr<Monster> monster)
{
    this->monster = std::move(monster);
}

void GameStateMediator::SetCommandCenter(std::unique_ptr<CommandCenter> command)
{
    this->commandCenter = std::move(command);
}

Monster *GameStateMediator::GetMonster()
{
    return this->monster.get();
}

std::reference_wrapper<const GameOptions> GameStateMediator::GetGameOptions()
{
    return std::reference_wrapper<const GameOptions>(*options);
}

