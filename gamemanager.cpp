#include "gamemanager.h"
#include "objects/human.h"
#include "objects/monster.h"
#include "objects/obstacle.h"

GameManager::GameManager()
{
}

void GameManager::DoTick(int userInput)
{
    mediator->DoTick(userInput);
}

void GameManager::PrepareEasy()
{
    prepareGame(Easy);
}

void GameManager::PrepareMedium()
{
    prepareGame(Medium);
}

void GameManager::PrepareHard()
{
    prepareGame(Hard);
}

std::vector<std::shared_ptr<Positionable>> GameManager::GetAllPositionable()
{
    if(!mediator){
        return std::vector<std::shared_ptr<Positionable>>();
    }
    return mediator.get()->getAll();
}

void GameManager::prepareGame(GameDifficulty)
{
    std::vector<std::shared_ptr<Positionable>> objects;
    std::unique_ptr<GameOptions> options = std::make_unique<GameOptions>(Easy);

    mediator = std::make_shared<GameStateMediator>( std::move(options));
    int id = 1;
    int dx = options->GetMapWidth()/(options->GetHumanAmount() + 1);
    int x = 0, y = options->GetMapHeight() - 20;
    for(int i = 0; i < options->GetHumanAmount(); id++, i++){
        x += dx;
        objects.push_back(std::make_shared<Human>(mediator,std::make_unique<Point>(x, y) ,id));
    }

    for(int i = 0; i < options->GetHumanAmount(); id++, i++){
        x += dx;
        objects.push_back(std::make_shared<Obstacle>(mediator,std::make_unique<Point>(x, y) ,id));
    }
    mediator->SetObjects(objects);
}
