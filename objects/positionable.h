#ifndef POSITIONABLE_H
#define POSITIONABLE_H

#include "point.h"
#include "baseobject.h"

///
/// \brief The Positionable class is a class Derived from BaseObject class.
///
/// The Positionable class is used to represent an object that has a position on the map in the game.
class Positionable : public BaseObject
{
public:
    ///
    /// Positionable constructor.
    /// @param mediator  Shared pointer to GameStateMediator class, the mediator of the game.
    /// @param location  Unique pointer to Point class, the starting location of the object.
    /// @param id        Integer, the id of the object.
    Positionable(std::shared_ptr<GameStateMediator>, std::unique_ptr<Point>, int);

    /// Radius is a constant integer that represents the radius of the object. Object
    const int Radius = 40;

    ///
    /// GetCoordinates is a function that returns the coordinates of the object.
    Point GetCoordinates() const;
    
    ///
    /// SetCoordinates is a function that sets the coordinates of the object.
    /// @param coordinates  Unique pointer to Point class, the coordinates of the object.
    void SetCoordinates(std::unique_ptr<Point>);
protected:
    std::unique_ptr<Point> coordinates;
};

#endif // POSITIONABLE_H
