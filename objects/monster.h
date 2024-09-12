#ifndef MONSTER_H
#define MONSTER_H

#include "movable.h"

///
/// \brief The Monster class is a class Derived from Movable class.
///
/// The Monster class is used to represent the monster in the game.
class Monster: public Movable
{
public:
    ///
    /// Monster constructor.
    /// @param mediator  Shared pointer to GameStateMediator class, the mediator of the game.
    /// @param location  Unique pointer to Point class, the starting location of the monster.
    /// @param id        Integer, the id of the monster.
    Monster(std::shared_ptr<GameStateMediator>,  std::unique_ptr<Point>, int);

    /// OnGameTick is a function that is called every game tick.
    /// It is responsible for moving the monster around the map.
    /// @param _userInput  Integer, the user input. It is an integer that has bits set depending on the direction the monster should move.
    void OnGameTick(int _userInput);
public:

    /// OnGameTick is a function that is called every game tick.
    /// Unused for the monster.
    void OnGameTick() override;
};

#endif // MONSTER_H
