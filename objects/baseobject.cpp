#include "baseobject.h"

BaseObject::BaseObject(std::shared_ptr<GameStateMediator> _pointer, int id)
{
    this->mediator = _pointer;
    this-> id = id;
}

void BaseObject::ReceiveEvent(std::unique_ptr<Event> event){
    this->events.push_back(std::move(event));
}

int BaseObject::GetId() const
{
    return this->id;
}

std::shared_ptr<GameStateMediator> BaseObject::GetMediator()
{
    return mediator;
}
