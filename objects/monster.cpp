#include "monster.h"
#include "utils.h"
Monster::Monster(std::shared_ptr<GameStateMediator> _mediator,
                 std::unique_ptr<Point> _location,
                 int _id) : Movable(_mediator, std::move(_location), _id, _mediator->GetGameOptions().get().GetMonsterSight(), _mediator->GetGameOptions().get().GetMonsterSpeed())
{

}

void Monster::OnGameTick(int _userInput)
{
    // it's a bit of a mess...
    double x = 0, y = 0;
    auto keysMap = Utils::GetKeysMap();
    if(_userInput & KEY_LEFT) x -= 1;
    if(_userInput & KEY_RIGHT) x += 1;
    if(_userInput & KEY_DOWN) y -= 1;
    if(_userInput & KEY_UP) y += 1;
    if(x != 0 || y != 0){
        double angle = 0;
        if(x) angle = 0.5 - x * 0.5;
        if(y) angle = 1+  y * 0.5;
        if(x == 1 && y == 1 )angle = 1.75;
        if(x == -1 && y == 1 )angle = 1.25;
        if(x == -1 && y == -1 )angle = 0.75;
        if(x == 1 && y == -1 )angle = 0.25;
        auto objects = mediator->getVisibleObjects(this);
        this->MoveInDirection(angle * M_PI, mediator->GetGameOptions().get().GetMonsterSpeed(), objects);
    }
    std::cout<<"[Monster "<<id<<"] position "<<coordinates->GetX()<<", "<<coordinates->GetY()<< " Input: "<<_userInput<<std::endl;
}

void Monster::OnGameTick()
{
}
