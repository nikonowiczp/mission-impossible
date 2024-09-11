#include "human.h"

#include "monster.h"
#include "events/commandcentercommandevent.h"
#include "events/humanfoundevent.h"

Human::Human(std::shared_ptr<GameStateMediator> _mediator,  std::unique_ptr<Point> _location, int _id): Movable(_mediator, std::move(_location), _id,
              _mediator->GetGameOptions().get().GetHumanSight(), _mediator->GetGameOptions().get().GetHumanSpeed())
{

}

void Human::OnGameTick()
{
    std::cout<<"[Human "<<id<<"] position "<<coordinates->GetX()<<", "<<coordinates->GetY()<<std::endl;
    auto visibleObjects = mediator->getVisibleObjects(this);
    for( const auto& object : visibleObjects){
        if(dynamic_cast<Monster*>(object)){
            std::cout<<"Monster found";
            auto event = std::make_unique<HumanFoundEvent>(std::make_unique<Point>(object->GetCoordinates().GetX(), object->GetCoordinates().GetY()));
            mediator->Notify(this, std::move(event));
        }
    }
    //TODO check event
    //TODO move
}
