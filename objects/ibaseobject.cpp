#include "ibaseobject.h"

IBaseObject::IBaseObject(std::shared_ptr<GameStateMediator> _pointer, std::unique_ptr<Point> _location)
{
    this->mediator = _pointer;
    this->Coordinates = std::move(_location);
}
