#ifndef COMMANDCENTER_H
#define COMMANDCENTER_H

#include "baseobject.h"

class CommandCenter : public BaseObject
{
public:
    CommandCenter(std::shared_ptr<GameStateMediator>, std::unique_ptr<Point> _location);
};

#endif // COMMANDCENTER_H
