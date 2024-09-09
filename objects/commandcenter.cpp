#include "commandcenter.h"

CommandCenter::CommandCenter(std::shared_ptr<GameStateMediator> _mediator): BaseObject(_mediator)
{

}

void CommandCenter::OnGameTick()
{
    auto visibleGameObject = this->mediator->getPeople();
}
