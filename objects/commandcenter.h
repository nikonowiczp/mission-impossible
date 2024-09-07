#ifndef COMMANDCENTER_H
#define COMMANDCENTER_H

#include "positionable.h"

class CommandCenter : public Positionable
{
public:
    CommandCenter(std::shared_ptr<GameStateMediator>, std::unique_ptr<Point> _location);
};

#endif // COMMANDCENTER_H
