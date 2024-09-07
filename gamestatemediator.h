#ifndef GAMESTATEMEDIATOR_H
#define GAMESTATEMEDIATOR_H

#include "events/ievent.h"
#include <stdint.h>
#include <vector>
// forward declaration - needed to avoid circular dependency
class BaseObject;
///
/// \brief The GameStateMediator class will be responsible for all of the communication between game objects.
/// It will also disconnected from any kind of state of the UI - a bit of a change compared to the diagram
/// Decided against interface - no need to create abstraction for no reason at all...
///
class GameStateMediator
{
public:
    GameStateMediator(std::vector<BaseObject>);
    void DoTick(int);
    void Notify(BaseObject, IEvent);

private:
    int64_t tick = 0;
    std::vector<BaseObject> gameObjects;
};

#endif // GAMESTATEMEDIATOR_H
