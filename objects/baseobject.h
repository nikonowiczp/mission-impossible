#ifndef BASEOBJECT_H
#define BASEOBJECT_H
#include "point.h"
#include "gamestatemediator.h"
#include <memory>
///
/// \brief The BaseObject class is the base class that will contain all of the logic of game objects
///
class BaseObject
{
public:
    BaseObject(std::shared_ptr<GameStateMediator>, std::unique_ptr<Point>);
    virtual void OnGameTick() = 0;
    Point GetCoordinates();
    void SetCoordinates(std::unique_ptr<Point>);
private:
    std::shared_ptr<GameStateMediator> mediator;
    int speed = 0;
    std::unique_ptr<Point> coordinates;
    void moveObject();
};

#endif // BASEOBJECT_H
