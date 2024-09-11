#include "obstacle.h"

Obstacle::Obstacle(std::shared_ptr<GameStateMediator> _mediator,  std::unique_ptr<Point> _location, int _id): Positionable(_mediator, std::move(_location), _id)
{

}

void Obstacle::OnGameTick()
{
    std::cout<<"[Obstacle "<<id<<"] position "<<coordinates->GetX()<<", "<<coordinates->GetY()<<std::endl;
}
