#include "monster.h"
#include "utils.h"
Monster::Monster(std::shared_ptr<GameStateMediator> _mediator,  std::unique_ptr<Point> _location, int _id) : Movable(_mediator, std::move(_location), _id, 0, _mediator->options->GetMonsterSpeed())
{

}

void Monster::OnGameTick(int _userInput)
{
    double x = 0, y = 0;
    auto keysMap = Utils::GetKeysMap();

    if(_userInput!= 0){
        std::cout<< "boo";
    }
    if(_userInput & KEY_LEFT) x -= 1;
    if(_userInput & KEY_RIGHT) x += 1;
    if(_userInput & KEY_DOWN) y += 1;
    if(_userInput & KEY_UP) y -= 1;
    x = x * mediator->options->GetMonsterSpeed() / std::sqrt(2);
    y = y * mediator->options->GetMonsterSpeed() /  std::sqrt(2);

    this->MoveBy(x, y);
    std::cout<<"[Monster "<<id<<"] position "<<coordinates->GetX()<<", "<<coordinates->GetY()<< " Input: "<<_userInput<<std::endl;
}

void Monster::OnGameTick()
{
}
