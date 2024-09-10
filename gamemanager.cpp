#include "gamemanager.h"


GameManager::GameManager()
{
}

void GameManager::PrepareEasy()
{
    prepareGame(Easy);
}

void GameManager::PrepareMedium()
{
    prepareGame(Easy);
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
    for(; id <= options->GetHumanAmount(); id++){
        x += dx;
        objects.push_back(std::make_shared<Positionable>(mediator,std::make_unique<Point>(x, y) ,id));
    }
    mediator->SetObjects(objects);

}
