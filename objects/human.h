#ifndef HUMAN_H
#define HUMAN_H

#include "positionable.h"

class Human: public Positionable
{
public:
    Human(std::shared_ptr<GameStateMediator>,  std::unique_ptr<Point>);
};

#endif // HUMAN_H
