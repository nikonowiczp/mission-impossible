#ifndef POSITIONABLE_H
#define POSITIONABLE_H

#include "point.h"
#include "baseobject.h"

class Positionable : public BaseObject
{
public:
    Positionable(std::shared_ptr<GameStateMediator>, std::unique_ptr<Point>);
    Point GetCoordinates();
    void SetCoordinates(std::unique_ptr<Point>);
private:
    std::unique_ptr<Point> coordinates;
};

#endif // POSITIONABLE_H
