#include "gamestatemediator.h"
#include "events/commandcentercommandevent.h"
#include "events/humanfoundevent.h"
#include "objects/commandcenter.h"
#include "objects/human.h"
#include "objects/movable.h"
#include "objects/monster.h"
#include "utils.h"

GameStateMediator::GameStateMediator(std::unique_ptr<GameOptions> options)
{
    this->options = std::move(options);
}

bool GameStateMediator::DoTick(int _userInput)
{
    assert(monster.get() != nullptr);
    assert(commandCenter.get() != nullptr);
    tick++;
    if(tick % options->GetTicksForNewHumans() == 0){
        gameObjects.push_back(std::make_unique<Human>(monster->GetMediator(),std::make_unique<Point>(1, 1) ,gameObjects.back()->GetId() + 1));
    }
    //do monster move
    for(const auto& a : gameObjects){
        if(dynamic_cast<Human*>(a.get()) && Utils::CalculateLength(monster.get(), a.get()) < options->GetHumanCatch()){
            return false;
        }
    }
    this->monster->OnGameTick(_userInput);


    this->commandCenter->OnGameTick();
    for(const auto& a : gameObjects){
        a->OnGameTick();
    }
    return true;
}

int GameStateMediator::GetTick() const
{
    return tick;
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
    if(_object->GetId() != monster->GetId() && Utils::CalculateLength(_object, monster.get()) < _object->GetRange()){
        _visibleObjects.push_back(monster.get());
    }
    return _visibleObjects;
}

std::vector<Positionable *> GameStateMediator::getPeople()
{
    std::vector<Positionable *> people;

    std::transform(gameObjects.begin(), gameObjects.end(), std::back_inserter(people),
                   [](const std::unique_ptr<Positionable>& ptr) -> Positionable* {
                       // Return only if ptr is a Human instance, else return nullptr
                       return dynamic_cast<Human*>(ptr.get());
                   });

    // Remove any nullptr values from the rawPtrs vector
    people.erase(std::remove(people.begin(), people.end(), nullptr), people.end());

    return people;
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

template<>
void GameStateMediator::Notify<Human, HumanFoundEvent>(Human* obj, std::unique_ptr<HumanFoundEvent> event){
    commandCenter->ReceiveEvent(std::move(event));
}

template<>
void GameStateMediator::Notify<CommandCenter, CommandCenterCommandEvent>(CommandCenter* obj, std::unique_ptr<CommandCenterCommandEvent> event){
    for(auto a : this->getPeople()){
        if(a->GetId() == event->id){
            a->ReceiveEvent(std::move(event));
            break;
        }
    }
    event.release();
}
