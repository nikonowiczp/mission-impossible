#include <stdexcept>

#include "movable.h"

Movable::Movable(std::shared_ptr<GameStateMediator> _mediator, std::unique_ptr<Point> _coordinates, int _id, double _range, double _speed) : Positionable(_mediator, std::move(_coordinates), _id)
{
    if (_range < 0 || _speed < 0) {
        throw std::invalid_argument("Speed and range must be positive or 0.");
    }
    this->range = _range;
    this->speed = _speed;
}

double Movable::GetRange()
{
    return this->range;
}

double Movable::GetSpeed()
{
    return this->speed;
}
