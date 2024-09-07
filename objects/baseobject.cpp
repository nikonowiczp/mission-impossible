#include "baseobject.h"

BaseObject::BaseObject(std::shared_ptr<GameStateMediator> _pointer)
{
    this->mediator = _pointer;
}

double BaseObject::GetRange()
{
    return this->range;
}
