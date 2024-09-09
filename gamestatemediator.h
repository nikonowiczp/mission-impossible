#ifndef GAMESTATEMEDIATOR_H
#define GAMESTATEMEDIATOR_H

#include <stdint.h>
#include <vector>
#include <memory>

#include "gameoptions.h"
#include "events/ievent.h"

// forward declaration - needed to avoid circular dependency
class BaseObject;
class Positionable;
class Movable;
class CommandCenter;
///
/// \brief The GameStateMediator class will be responsible for all of the communication between game objects.
/// It's also disconnected from any kind of state of the UI - a bit of a change compared to the diagram in stage 2
/// Decided against interface - no need to create abstraction for no reason at all...
///
class GameStateMediator
{
public:
    GameStateMediator(std::vector<std::shared_ptr<Positionable>>, std::unique_ptr<GameOptions>);
    void DoTick(int);
    void Notify(BaseObject, IEvent);

    std::vector<std::shared_ptr<Positionable>> getVisibleObjects(std::shared_ptr<Movable>);
    std::vector<std::shared_ptr<Positionable>> getPeople();
    std::vector<std::shared_ptr<Positionable>> getAll();
private:
    int64_t tick = 0;
    std::unique_ptr<CommandCenter> commandCenter;
    std::vector<std::shared_ptr<Positionable>> gameObjects;
    std::unique_ptr<GameOptions> options;
};

#endif // GAMESTATEMEDIATOR_H
