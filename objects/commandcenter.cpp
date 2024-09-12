#include "commandcenter.h"

CommandCenter::CommandCenter(std::shared_ptr<GameStateMediator> _mediator, int _id): BaseObject(_mediator, _id)
{

}

void CommandCenter::OnGameTick()
{
    std::cout<<"[Command center "<<id<<"] "<<std::endl;
    auto humans = mediator->getPeople();
    std::unique_ptr<Point> point = nullptr;
    if(events.size()>0){

    }
}
