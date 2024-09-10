#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "objects/positionable.h"
#include "gamestatemediator.h"
#include "objects/commandcenter.h"
#include "gameoptions.h"
///
/// \brief The GameManager class will create all of the necessary objects to start a game. It will also generate game ticks and be the adapter between ui and game itself
///
class GameManager
{
public:
    GameManager();
    void PrepareEasy();
    void PrepareMedium();
    void PrepareHard();

    int GetWidth();
    int GetHeight();

    std::vector<std::shared_ptr<Positionable>> GetAllPositionable();
private:
    void prepareGame(GameDifficulty);
    std::shared_ptr<GameStateMediator> mediator;
};

#endif // GAMEMANAGER_H
