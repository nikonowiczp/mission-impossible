#ifndef HUMAN_H
#define HUMAN_H

#include "baseobject.h"

class Human: public BaseObject
{
public:
    Human(std::shared_ptr<GameStateMediator>,  std::unique_ptr<Point>);
};

#endif // HUMAN_H
