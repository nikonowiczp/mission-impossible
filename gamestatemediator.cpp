#include "gamestatemediator.h"
#include "objects/baseobject.h"

GameStateMediator::GameStateMediator(std::vector<BaseObject> objects)
{
    this->gameObjects = std::move(objects);
}

void GameStateMediator::DoTick(int _userInput)
{

    tick++;
}
