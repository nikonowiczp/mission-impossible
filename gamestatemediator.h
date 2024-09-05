#ifndef GAMESTATEMEDIATOR_H
#define GAMESTATEMEDIATOR_H

#include "objects/ibaseobject.h"
#include "events/ievent.h"
#include <stdint.h>
#include <vector>
///
/// \brief The GameStateMediator class will be responsible for all of the communication between game objects.
/// It will also disconnected from any kind of state of the UI - a bit of a change compared to the diagram
/// Decided against interface - no need to create abstraction for no reason at all...
///
class GameStateMediator
{
public:
    GameStateMediator(std::vector<IBaseObject>);
    void DoTick(int userInput);
    void Notify(IBaseObject, IEvent);

private:
    int64_t tick = 0;
    std::vector<IBaseObject> gameObjects;
};

#endif // GAMESTATEMEDIATOR_H
