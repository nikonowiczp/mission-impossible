#ifndef GAMESTATEMEDIATOR_H
#define GAMESTATEMEDIATOR_H

#include <stdint.h>
#include <vector>
#include <memory>

#include "gameoptions.h"
#include "events/event.h"

// forward declaration - needed to avoid circular dependency
class BaseObject;
class Positionable;
class Movable;
class CommandCenter;
class Monster;
///
/// \brief The GameStateMediator class will be responsible for all of the communication between game objects.
/// It's also disconnected from any kind of state of the UI - a bit of a change compared to the diagram in stage 2
/// Decided against interface - no need to create abstraction for no reason at all...
///
class GameStateMediator
{
public:
    GameStateMediator(std::unique_ptr<GameOptions>);
    bool DoTick(int);

    // raw pointer to objtype because we dont transfer ownership
    // unique pointer to event because we transfer ownership
    template<typename ObjType, typename EventType>
    void Notify(ObjType *, std::unique_ptr<EventType>);

    int GetTick() const;
    // we do not give ownership, so we return references
    std::vector<Positionable *> getVisibleObjects(Movable*);
    std::vector<Positionable *> getPeople();
    std::vector<Positionable *> getAll();

    void SetObjects(std::vector<std::unique_ptr<Positionable>>);
    void SetMonster(std::unique_ptr<Monster>);
    void SetCommandCenter(std::unique_ptr<CommandCenter>);
    Monster* GetMonster();
    std::reference_wrapper<const GameOptions> GetGameOptions();
private:
    int64_t tick = 0;
    std::unique_ptr<GameOptions> options;

    std::unique_ptr<CommandCenter> commandCenter;
    std::vector<std::unique_ptr<Positionable>> gameObjects;
    std::unique_ptr<Monster> monster;
};

#endif // GAMESTATEMEDIATOR_H
