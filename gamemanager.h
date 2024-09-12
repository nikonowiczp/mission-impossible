#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "objects/positionable.h"
#include "gamestatemediator.h"
#include "objects/commandcenter.h"
#include "gameoptions.h"
///
/// \brief The GameManager class is a class that manages the game. 
///
/// The GameManager class is the only point that UI interacts with the game.
/// It is responsible for creating the game for every difficulty
class GameManager
{
public:
    /// GameManager constructor.
    GameManager();

    /// DoTick is a function that is called every game tick.
    bool DoTick(int userInput);

    /// GetTick is a function that returns the current tick of the game.
    int GetTick() const;

    /// PrepareEasy is a function that prepares the game for easy difficulty.
    void PrepareEasy();
    /// PrepareMedium is a function that prepares the game for medium difficulty.
    void PrepareMedium();
    /// PrepareHard is a function that prepares the game for hard difficulty.
    void PrepareHard();

    /// GetWidth is a function that returns the width of the game map.
    int GetWidth() const;
    int GetHeight() const;

    /// GetAllPositionable is a function that returns all the positionable objects in the game.
    /// User by the UI to draw the game.
    std::vector<Positionable*> GetAllPositionable();

    /// GetMonster is a function that returns the monster in the game.
    /// User by the UI to save that time needed to find the monster among objects
    Monster* GetMonster();
private:
    void prepareGame(GameDifficulty);
    std::shared_ptr<GameStateMediator> mediator;
};

#endif // GAMEMANAGER_H
