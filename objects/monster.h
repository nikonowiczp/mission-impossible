#ifndef MONSTER_H
#define MONSTER_H

#include "ibaseobject.h"
class Monster: public IBaseObject
{
public:
    Monster(std::shared_ptr<GameStateMediator>,  std::unique_ptr<Point> _location);
};

#endif // MONSTER_H
