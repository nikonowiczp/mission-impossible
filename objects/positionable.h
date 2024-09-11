#ifndef POSITIONABLE_H
#define POSITIONABLE_H

#include "point.h"
#include "baseobject.h"

class Positionable : public BaseObject
{
public:
    Positionable(std::shared_ptr<GameStateMediator>, std::unique_ptr<Point>, int);

    const int Radius = 40;
    Point GetCoordinates();
    void SetCoordinates(std::unique_ptr<Point>);
protected:
    std::unique_ptr<Point> coordinates;
};

#endif // POSITIONABLE_H
