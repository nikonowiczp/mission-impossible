#ifndef MOVABLE_H
#define MOVABLE_H

#include "positionable.h"

class Movable : public Positionable
{
public:
    Movable(std::shared_ptr<GameStateMediator> _mediator, std::unique_ptr<Point> _coordinates,int _id, double _range, double _speed);
    double GetRange() const;
    double GetSpeed() const;
public:
    void MoveInDirection(double angle, double length, const std::vector<Positionable*>& others);
private:
    double speed = 0;
    double range = 0;
    bool CanMoveTo(double newX, double newY, const std::vector<Positionable*>& others);
};

#endif // MOVABLE_H
