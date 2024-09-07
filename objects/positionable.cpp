#include "positionable.h"

Positionable::Positionable(std::shared_ptr<GameStateMediator> _mediator, std::unique_ptr<Point> _coordinates) : BaseObject(_mediator)
{
    this->coordinates = std::move(_coordinates);
}

Point Positionable::GetCoordinates()
{
    return Point(this->coordinates->GetX(), this->coordinates->GetY());
}

void Positionable::SetCoordinates(std::unique_ptr<Point> _coordinates)
{
    this->coordinates = std::move(_coordinates);
}
