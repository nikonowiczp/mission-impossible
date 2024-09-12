#ifndef HUMANFOUNDEVENT_H
#define HUMANFOUNDEVENT_H

#include "event.h"
#include "point.h"

#include <memory>
class HumanFoundEvent: public Event
{
public:
    HumanFoundEvent(std::unique_ptr<Point>);

    std::unique_ptr<Point> Location;
};

#endif // HUMANFOUNDEVENT_H
