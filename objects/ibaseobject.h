#ifndef IBASEOBJECT_H
#define IBASEOBJECT_H
#include "point.h"
#include "gamestatemediator.h"
#include <memory>
///
/// \brief The IBaseObject class is the base class that will contain all of the logic of game objects
///
class IBaseObject
{
public:
    IBaseObject(std::shared_ptr<GameStateMediator>, std::unique_ptr<Point>);
    virtual void OnGameTick() = 0;
    Point GetCoordinates();
    void SetCoordinates(std::unique_ptr<Point>);
private:
    std::shared_ptr<GameStateMediator> mediator;
    int speed = 0;
    std::unique_ptr<Point> coordinates;
    void moveObject();
};

#endif // IBASEOBJECT_H
