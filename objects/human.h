#ifndef HUMAN_H
#define HUMAN_H

#include "positionable.h"

class Human: public Positionable
{
public:
    Human(std::shared_ptr<GameStateMediator>,  std::unique_ptr<Point>, int);

    // BaseObject interface
public:
    void OnGameTick();
};

#endif // HUMAN_H
