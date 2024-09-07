#ifndef HUMAN_H
#define HUMAN_H

#include "ibaseobject.h"

class Human: public IBaseObject
{
public:
    Human(std::shared_ptr<GameStateMediator>,  std::unique_ptr<Point>);
};

#endif // HUMAN_H
