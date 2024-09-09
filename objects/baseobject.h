#ifndef BASEOBJECT_H
#define BASEOBJECT_H
#include "gamestatemediator.h"
#include <memory>
///
/// \brief The BaseObject class is the base class that will contain all of the logic of game objects
///
class BaseObject
{
public:
    BaseObject(std::shared_ptr<GameStateMediator>);
    virtual void OnGameTick() = 0;
    void ReceiveEvent(std::unique_ptr<IEvent>);
protected:
    std::unique_ptr<IEvent> event = nullptr;
    std::shared_ptr<GameStateMediator> mediator;
};

#endif // BASEOBJECT_H
