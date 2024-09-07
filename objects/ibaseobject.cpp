#include "ibaseobject.h"

IBaseObject::IBaseObject(std::shared_ptr<GameStateMediator> _pointer, std::unique_ptr<Point> _location)
{
    this->mediator = _pointer;
    this->coordinates = std::move(_location);
}

Point IBaseObject::GetCoordinates()
{
    return Point(this->coordinates->GetX(), this->coordinates->GetY());
}

void IBaseObject::SetCoordinates(std::unique_ptr<Point> _coordinates)
{
    this->coordinates = std::move(_coordinates);
}
