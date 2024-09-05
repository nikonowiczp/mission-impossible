#include "gamestatemediator.h"


GameStateMediator::GameStateMediator(std::vector<IBaseObject> objects)
{
    this->gameObjects = std::move(objects);
}

void GameStateMediator::DoTick()
{
    for(auto a : gameObjects){
        a.onGameTick();
    }
    tick++;
}
