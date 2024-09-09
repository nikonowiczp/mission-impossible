#include "commandcenter.h"

CommandCenter::CommandCenter(std::shared_ptr<GameStateMediator> _mediator): BaseObject(_mediator, 0)
{

}

void CommandCenter::OnGameTick()
{
}
