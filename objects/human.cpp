#include "human.h"

Human::Human(std::shared_ptr<GameStateMediator> _mediator,  std::unique_ptr<Point> _location, int _id): Positionable(_mediator, std::move(_location), _id)
{

}

void Human::OnGameTick()
{
    std::cout<<"[Human "<<id<<"] position "<<coordinates->GetX()<<", "<<coordinates->GetY()<<std::endl;
}
