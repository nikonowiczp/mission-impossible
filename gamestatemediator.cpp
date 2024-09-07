#include "gamestatemediator.h"
#include "objects/ibaseobject.h"

GameStateMediator::GameStateMediator(std::vector<IBaseObject> objects)
{
    this->gameObjects = std::move(objects);
}

void GameStateMediator::DoTick(int _userInput)
{

    tick++;
}
