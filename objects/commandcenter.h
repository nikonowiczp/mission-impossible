#ifndef COMMANDCENTER_H
#define COMMANDCENTER_H

#include "positionable.h"

class CommandCenter : public BaseObject
{
public:
    CommandCenter(std::shared_ptr<GameStateMediator>);
    void OnGameTick();
};

#endif // COMMANDCENTER_H
