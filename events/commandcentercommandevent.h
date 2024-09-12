#ifndef COMMANDCENTERCOMMANDEVENT_H
#define COMMANDCENTERCOMMANDEVENT_H

#include "event.h"
#include "point.h"
#include <memory>

class CommandCenterCommandEvent : public Event
{
public:
    CommandCenterCommandEvent(std::unique_ptr<Point>, int id, int skew);

    std::unique_ptr<Point> location;
    int id;
    int skew;
};

#endif // COMMANDCENTERCOMMANDEVENT_H
