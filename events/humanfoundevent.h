#ifndef HUMANFOUNDEVENT_H
#define HUMANFOUNDEVENT_H

#include "event.h"
#include "point.h"

#include <memory>

///
/// \brief The HumanFoundEvent class is a class Derived from Event class.
///
/// The HumanFoundEvent class is used to generate an event when a human found a monster.
class HumanFoundEvent: public Event
{
public:
    /// HumanFoundEvent constructor.
    /// @param location  Unique pointer to Point class, the location of the monster.
    HumanFoundEvent(std::unique_ptr<Point>);

    /// Unique pointer to Point class, the location of the monster.
    std::unique_ptr<Point> Location;
};

#endif // HUMANFOUNDEVENT_H
