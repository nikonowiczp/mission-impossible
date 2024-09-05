#include "ibaseobject.h"

IBaseObject::IBaseObject(std::shared_ptr<GameStateMediator> pointer)
{
    this->mediator = pointer;
}
