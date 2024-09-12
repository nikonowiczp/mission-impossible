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
/// \brief The GameStateMediator is a class responsible for all of the communication between game objects.
/// It's also disconnected from any kind of state of the UI - a bit of a change compared to the diagram in stage 2
/// Decided against interface - no need to create abstraction for no reason at all...
class GameStateMediator
{
public:
    /// GameStateMediator constructor.
    /// @param options  Unique pointer to GameOptions class, the options of the game.
    GameStateMediator(std::unique_ptr<GameOptions>);

    /// DoTick is a function that is called every game tick.
    /// @param userInput  Integer, the user input.
    bool DoTick(int);

    template<typename ObjType, typename EventType>
    /// Notify is a function that notifies the mediator of an event.
    /// @param obj  Pointer to ObjType class, the object that is notifying the mediator.
    /// raw pointer to objtype because we dont transfer ownership
    /// @param event  Unique pointer to EventType class, the event that is being notified.
    /// unique pointer to event because we transfer ownership
    void Notify(ObjType *, std::unique_ptr<EventType>);

    /// GetTick is a function that returns the current tick of the game.
    int GetTick() const;
    // we do not give ownership, so we return references

    /// GetVisibleObjects is a function that returns all the visible objects for a given movable object.
    /// @param Movable  Pointer to Movable class, the object that will see the objects.
    std::vector<Positionable *> getVisibleObjects(Movable*);
    /// GetPeople is a function that returns all the people in the game.
    std::vector<Positionable *> getPeople();
    /// GetAll is a function that returns all the objects in the game.
    std::vector<Positionable *> getAll();

    ///
    /// SetObjects is a function that sets the all positionable objects in the game.
    /// @param objects  Vector of unique pointers to Positionable class, the objects to be set.
    void SetObjects(std::vector<std::unique_ptr<Positionable>>);
    /// SetMonster is a function that sets the monster.
    /// @param monster  Unique pointer to Monster class, the monster to be set.
    void SetMonster(std::unique_ptr<Monster>);
    /// SetCommandCenter is a function that sets the command center.
    /// @param commandCenter  Unique pointer to CommandCenter class, the command center to be set.
    void SetCommandCenter(std::unique_ptr<CommandCenter>);

    /// GetMonster is a function that returns the monster in the game.
    Monster* GetMonster();

    /// GetGameOptions is a function that returns the game options.
    std::reference_wrapper<const GameOptions> GetGameOptions();
private:
    int64_t tick = 0;
    std::unique_ptr<GameOptions> options;

    std::unique_ptr<CommandCenter> commandCenter;
    std::vector<std::unique_ptr<Positionable>> gameObjects;
    std::unique_ptr<Monster> monster;
};

#endif // GAMESTATEMEDIATOR_H
