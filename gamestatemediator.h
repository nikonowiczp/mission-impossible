#ifndef GAMESTATEMEDIATOR_H
#define GAMESTATEMEDIATOR_H

#include "events/ievent.h"
#include <stdint.h>
#include <vector>
#include <memory>
// forward declaration - needed to avoid circular dependency
class BaseObject;
class Positionable;
class Movable;
///
/// \brief The GameStateMediator class will be responsible for all of the communication between game objects.
/// It's also disconnected from any kind of state of the UI - a bit of a change compared to the diagram in stage 2
/// Decided against interface - no need to create abstraction for no reason at all...
///
class GameStateMediator
{
public:
    GameStateMediator(std::vector<std::shared_ptr<Positionable>>);
    void DoTick(int);
    void Notify(BaseObject, IEvent);

private:
    int64_t tick = 0;
    std::vector<std::shared_ptr<Positionable>> gameObjects;
    std::vector<std::shared_ptr<Positionable>> getVisibleObjects(std::shared_ptr<Movable>);
};

#endif // GAMESTATEMEDIATOR_H
