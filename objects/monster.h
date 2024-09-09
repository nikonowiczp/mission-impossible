#ifndef MONSTER_H
#define MONSTER_H

#include "positionable.h"
class Monster: public Positionable
{
public:
    Monster(std::shared_ptr<GameStateMediator>,  std::unique_ptr<Point>, int);
};

#endif // MONSTER_H
