#ifndef COMMANDCENTERCOMMANDEVENT_H
#define COMMANDCENTERCOMMANDEVENT_H

#include "event.h"
#include "point.h"
#include <memory>

///
/// \brief The CommandCenterCommandEvent class is a class Derived from Event class.
///
/// The CommandCenterCommandEvent class is used to generate an event when the command center sends a command to a human 
class CommandCenterCommandEvent : public Event
{
public:
    ///
    /// CommandCenterCommandEvent constructor.
    /// @param location  Unique pointer to Point class, the location of the command.
    /// @param id        Integer, the id of the command.
    /// @param skew      Integer, the skew of the command. Used to change the direction of human - unused
    CommandCenterCommandEvent(std::unique_ptr<Point>, int id, int skew);

    std::unique_ptr<Point> location;
    int id;
    int skew;
};

#endif // COMMANDCENTERCOMMANDEVENT_H
