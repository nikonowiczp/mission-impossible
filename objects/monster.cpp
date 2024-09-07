#include "monster.h"

Monster::Monster(std::shared_ptr<GameStateMediator> mediator,  std::unique_ptr<Point> _location) : BaseObject(mediator, std::move(_location))
{

}
