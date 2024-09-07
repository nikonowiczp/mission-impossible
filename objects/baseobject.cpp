#include "baseobject.h"

BaseObject::BaseObject(std::shared_ptr<GameStateMediator> _pointer, std::unique_ptr<Point> _location)
{
    this->mediator = _pointer;
    this->coordinates = std::move(_location);
}

Point BaseObject::GetCoordinates()
{
    return Point(this->coordinates->GetX(), this->coordinates->GetY());
}

void BaseObject::SetCoordinates(std::unique_ptr<Point> _coordinates)
{
    this->coordinates = std::move(_coordinates);
}

double BaseObject::GetRange()
{
    return this->range;
}
