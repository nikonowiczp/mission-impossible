#include "human.h"

Human::Human(std::shared_ptr<GameStateMediator> _mediator,  std::unique_ptr<Point> _location): Positionable(_mediator, std::move(_location))
{

}
