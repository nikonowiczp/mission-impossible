#ifndef BASEOBJECT_H
#define BASEOBJECT_H
#include "gamestatemediator.h"
#include <iostream>
#include <memory>
///
/// \brief The BaseObject class is the base class that will contain all of the logic of game objects
///
class BaseObject
{
public:
    BaseObject(std::shared_ptr<GameStateMediator>, int);
    virtual void OnGameTick() = 0;
    void ReceiveEvent(std::unique_ptr<Event>);
    int GetId() const;
    std::shared_ptr<GameStateMediator> GetMediator();

protected:
    int id;
    std::vector<std::unique_ptr<Event>> events;
    std::shared_ptr<GameStateMediator> mediator;
};

#endif // BASEOBJECT_H
