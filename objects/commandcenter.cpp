#include "commandcenter.h"

CommandCenter::CommandCenter(std::shared_ptr<GameStateMediator> _mediator, int _id): BaseObject(_mediator, _id)
{

}

void CommandCenter::OnGameTick()
{
    std::cout<<"[Command center "<<id<<"] "<<std::endl;
}
