#include "human.h"

Human::Human(std::shared_ptr<GameStateMediator> _mediator,  std::unique_ptr<Point> _location, int _id): Movable(_mediator, std::move(_location), _id,
            _mediator->options->GetHumanSight(), _mediator->options->GetHumanSpeed())
{

}

void Human::OnGameTick()
{
    std::cout<<"[Human "<<id<<"] position "<<coordinates->GetX()<<", "<<coordinates->GetY()<<std::endl;
}
