#include "commandcenter.h"
#include "events/commandcentercommandevent.h"
#include "events/humanfoundevent.h"
#include "utils.h"
CommandCenter::CommandCenter(std::shared_ptr<GameStateMediator> _mediator, int _id): BaseObject(_mediator, _id)
{

}

void CommandCenter::OnGameTick()
{
    std::cout<<"[Command center "<<id<<"] "<<std::endl;
    auto humans = mediator->getPeople();
    std::unique_ptr<Point> point = nullptr;
    bool eventFound = false;
    int x = -1, y = -1;
    if(events.size()){
        // we found a human
        bool sent=false;
        for(const auto & a : events){
            if(HumanFoundEvent* humanFoundEvent =dynamic_cast<HumanFoundEvent *>(a.get())){
                x = humanFoundEvent->Location->GetX();
                y = humanFoundEvent->Location->GetY();
                eventFound = true;
                break;
            }
        }
        events.clear();
    }

    if(eventFound){
        for(const auto& human : humans){
            std::unique_ptr<CommandCenterCommandEvent> event = make_unique<CommandCenterCommandEvent>(std::make_unique<Point>(x, y), human->GetId(), 0);
            mediator->Notify(this, std::move(event));
        }
    }
}
