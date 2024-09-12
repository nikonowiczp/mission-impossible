#ifndef OBSTACLE_H
#define OBSTACLE_H
#include "objects/positionable.h"

///
/// \brief The Obstacle class is a class Derived from Positionable class.
///
/// The Obstacle class is used to represent the obstacles in the game. 
/// The Obstacle is non movable object that blocks the way of the human and the monster.
class Obstacle: public Positionable
{
public:
    ///
    /// Obstacle constructor.
    /// @param mediator  Shared pointer to GameStateMediator class, the mediator of the game.
    /// @param location  Unique pointer to Point class, the starting location of the obstacle.
    /// @param id        Integer, the id of the obstacle.
    Obstacle(std::shared_ptr<GameStateMediator>,  std::unique_ptr<Point>, int);

    // BaseObject interface
public:
    void OnGameTick();
};

#endif // OBSTACLE_H
