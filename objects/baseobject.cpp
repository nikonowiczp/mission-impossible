#include "baseobject.h"

BaseObject::BaseObject(std::shared_ptr<GameStateMediator> _pointer)
{
    this->mediator = _pointer;
}

void BaseObject::ReceiveEvent(std::unique_ptr<IEvent> event){
    this->event = std::move(event);
}
