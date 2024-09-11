#ifndef OBSTACLE_H
#define OBSTACLE_H
#include "objects/positionable.h"

class Obstacle: public Positionable
{
public:
    Obstacle(std::shared_ptr<GameStateMediator>,  std::unique_ptr<Point>, int);

    // BaseObject interface
public:
    void OnGameTick();
};

#endif // OBSTACLE_H
