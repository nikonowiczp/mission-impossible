#ifndef MOVABLE_H
#define MOVABLE_H

#include "positionable.h"

class Movable : public Positionable
{
public:
    Movable(std::shared_ptr<GameStateMediator> _mediator, std::unique_ptr<Point> _coordinates,int _id, double _range, double _speed);
    double GetRange();
    double GetSpeed();
private:
    double speed = 0;
    double range = 0;
    virtual void move() = 0;
};

#endif // MOVABLE_H
