#include "human.h"

Human::Human(std::shared_ptr<GameStateMediator> mediator,  std::unique_ptr<Point> _location): IBaseObject(mediator, std::move(_location))
{

}
