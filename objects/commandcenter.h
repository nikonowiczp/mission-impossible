#ifndef COMMANDCENTER_H
#define COMMANDCENTER_H

#include "positionable.h"

/// 
/// \brief The CommandCenter class is a class Derived from BaseObject class.
///
/// The CommandCenter class is used to represent the command center in the game.
class CommandCenter : public BaseObject
{
public:
    /// CommandCenter constructor.
    /// @param mediator  Shared pointer to GameStateMediator class, the mediator of the game.
    /// @param id        Integer, the id of the object.
    CommandCenter(std::shared_ptr<GameStateMediator>, int);

    /// OnGameTick is a function that is called every game tick.
    void OnGameTick() override;
};

#endif // COMMANDCENTER_H
