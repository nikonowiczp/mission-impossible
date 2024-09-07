#ifndef MONSTER_H
#define MONSTER_H

#include "baseobject.h"
class Monster: public BaseObject
{
public:
    Monster(std::shared_ptr<GameStateMediator>,  std::unique_ptr<Point> _location);
};

#endif // MONSTER_H
