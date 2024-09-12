#include "human.h"

#include "monster.h"
#include "events/commandcentercommandevent.h"
#include "events/humanfoundevent.h"
#include <random>

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

    switch (currentState) {
    case Scouting:{
        doScouting(visibleObjects);
        break;
    }
    case PursuingFar:{
        break;
    }
    case PursuingClose:{
        break;
    }
    default:
        break;
    }
}

void Human::doScouting(const std::vector<Positionable*>& others)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(-0.01, 0.01);
    std::uniform_real_distribution<> dist2(0, 2 * M_PI);

    double angle = currentScoutingAngle + dist(gen);
    int i = 0;
    while(!this->MoveInDirection(angle, this->mediator->GetGameOptions().get().GetHumanSpeed(), others)){
        i++;
        currentScoutingAngle =  dist2(gen);
        angle = currentScoutingAngle;
        if(i > 5) break;
    }
}
