#ifndef MOVABLE_H
#define MOVABLE_H

#include "positionable.h"

///
/// \brief The Movable class is a class Derived from Positionable class.
///
/// The Movable class is used to represent objects that can move in the game.
class Movable : public Positionable
{
public:
    ///
    /// Movable constructor.
    /// @param _mediator  Shared pointer to GameStateMediator class, the mediator of the game.
    /// @param _coordinates  Unique pointer to Point class, the starting location of the object.
    /// @param _id  Integer, the id of the object.
    /// @param _range  Double, the range of view of the object
    /// @param _speed  Double, the speed of the object
    Movable(std::shared_ptr<GameStateMediator> _mediator, std::unique_ptr<Point> _coordinates,int _id, double _range, double _speed);

    /// 
    /// GetRange is a function that returns the range of view of the the object.
    double GetRange() const;

    ///
    /// GetSpeed is a function that returns the speed of the the object.
    double GetSpeed() const;

    ///
    /// MoveInDirection is a function that moves the object in a direction.
    /// @param angle  Double, the angle of the direction in radians
    /// @param length  Double, the length of the movement
    /// @param others  Vector of Positionable pointers, the other objects in the game that the object should avoid
    /// @param tryToAvoid  Boolean, whether the object should try to avoid the other objects. Used for human only.
    bool MoveInDirection(double angle, const std::vector<Positionable*>& others, bool tryToAvoid = false);
private:
    double speed = 0;
    double range = 0;
    bool CanMoveTo(double newX, double newY, const std::vector<Positionable*>& others);
};

#endif // MOVABLE_H
