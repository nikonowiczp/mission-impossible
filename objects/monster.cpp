#include "monster.h"

Monster::Monster(std::shared_ptr<GameStateMediator> _mediator,  std::unique_ptr<Point> _location, int _id) : Positionable(_mediator, std::move(_location), _id)
{

}
