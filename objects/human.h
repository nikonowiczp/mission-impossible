#ifndef HUMAN_H
#define HUMAN_H

#include "movable.h"

class Human: public Movable
{
public:
    Human(std::shared_ptr<GameStateMediator>,  std::unique_ptr<Point>, int);

    // BaseObject interface
public:
    void OnGameTick();
};

#endif // HUMAN_H
