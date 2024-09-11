#ifndef HUMANFOUNDEVENT_H
#define HUMANFOUNDEVENT_H

#include "ievent.h"
#include "point.h"

#include <memory>
class HumanFoundEvent: public IEvent
{
public:
    HumanFoundEvent(std::unique_ptr<Point>);

    std::unique_ptr<Point> Location;
};

#endif // HUMANFOUNDEVENT_H
