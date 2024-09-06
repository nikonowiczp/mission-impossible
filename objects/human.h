#ifndef HUMAN_H
#define HUMAN_H

#include "ibaseobject.h"

class Human: public IBaseObject
{
public:
    Human(std::shared_ptr<GameStateMediator>);
};

#endif // HUMAN_H
