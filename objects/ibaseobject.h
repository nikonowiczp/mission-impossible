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
    IBaseObject(std::shared_ptr<GameStateMediator>);
    virtual void OnGameTick() = 0;
    Point Coordinates;

private:
    std::shared_ptr<GameStateMediator> mediator;
    int speed = 0;
    void moveObject();
};

#endif // IBASEOBJECT_H
