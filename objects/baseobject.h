#ifndef BASEOBJECT_H
#define BASEOBJECT_H
#include "gamestatemediator.h"
#include <iostream>
#include <memory>

///
/// \brief The BaseObject class is the base class that all of the objects in the game inherit from.
///
/// The BaseObject class
class BaseObject
{
public:
    /// BaseObject constructor.
    /// @param mediator  Shared pointer to GameStateMediator class, the mediator of the game.
    /// @param id        Integer, the id of the object.
    BaseObject(std::shared_ptr<GameStateMediator>, int);
    
    /// OnGameTick is a pure virtual function that is called every game tick.
    virtual void OnGameTick() = 0;
    /// ReceiveEvent is a function that receives an event and writes it to the events vector.
    /// @param event  Unique pointer to Event class, the event to be received.
    void ReceiveEvent(std::unique_ptr<Event>);

    /// GetId is a function that returns the id of the object.
    int GetId() const;

    /// GetMediator is a function that returns the mediator of the object.
    std::shared_ptr<GameStateMediator> GetMediator();

protected:
    /// Integer, the id of the object.
    int id;
    /// Vector of unique pointers to Event class, the events that the object has received.
    std::vector<std::unique_ptr<Event>> events;
    /// Shared pointer to GameStateMediator class, the mediator of the game.
    std::shared_ptr<GameStateMediator> mediator;
};

#endif // BASEOBJECT_H
