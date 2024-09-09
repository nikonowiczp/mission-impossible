#include "gamemanager.h"


GameManager::GameManager()
{
}

void GameManager::PrepareEasy()
{
    std::vector<std::shared_ptr<Positionable>> objects;
    std::unique_ptr<GameOptions> options = std::make_unique<GameOptions>(Easy);
    mediator = std::make_unique<GameStateMediator>(objects, std::move(options));
}

void GameManager::PrepareMedium()
{

}

void GameManager::PrepareHard()
{

}

std::vector<std::shared_ptr<Positionable>> GameManager::GetAllPositionable()
{
    if(!mediator){
        return std::vector<std::shared_ptr<Positionable>>();
    }
    return mediator.get()->getAll();
}
