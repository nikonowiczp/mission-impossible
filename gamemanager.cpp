#include "gamemanager.h"
#include "objects/human.h"
#include "objects/monster.h"
#include "objects/obstacle.h"
#include "utils.h"
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

int GameManager::GetWidth()
{
    return mediator->options->GetMapWidth();
}

int GameManager::GetHeight()
{
    return mediator->options->GetMapHeight();
}

std::vector<std::shared_ptr<Positionable>> GameManager::GetAllPositionable()
{
    if(!mediator){
        return std::vector<std::shared_ptr<Positionable>>();
    }
    return mediator.get()->getAll();
}

Monster *GameManager::GetMonster()
{
    return mediator->GetMonster();
}

void GameManager::prepareGame(GameDifficulty difficulty)
{
    std::vector<std::shared_ptr<Positionable>> objects;
    std::unique_ptr<GameOptions> options = std::make_unique<GameOptions>(difficulty);
    mediator = std::make_shared<GameStateMediator>( std::make_unique<GameOptions>(difficulty));

    int id = 1;

    mediator->SetMonster(std::make_unique<Monster>(mediator,std::make_unique<Point>(options->GetMapWidth()/2, options->GetMapHeight()/2) ,id));
    id ++;
    mediator->SetCommandCenter(std::make_unique<CommandCenter>(mediator, id));
    id ++;

    int dx = options->GetMapWidth()/(options->GetHumanAmount() + 1);
    int x = 0, y = options->GetMapHeight() - 20;
    for(int i = 0; i < options->GetHumanAmount(); id++, i++){
        x += dx;
        objects.push_back(std::make_shared<Human>(mediator,std::make_unique<Point>(x, y) ,id));
    }
    std::srand(static_cast<unsigned int>(std::time(0)));
    for(int i = 0; i < options->GetObstacleAmount(); id++, i++){
        int newX, newY, j = 0;
        do {
            newX = rand() % options->GetMapWidth();
            newY = rand() % options->GetMapHeight();
            j++;
            // safeguard just in case the random generation fails
            if(j>100) break;
        } while (!Utils::IsCloseToAny(objects, newX, newY));

        objects.push_back(std::make_shared<Obstacle>(mediator,std::make_unique<Point>(newX, newY) ,id));
    }
    mediator->SetObjects(objects);
}
