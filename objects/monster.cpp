#include "monster.h"
#include "utils.h"
Monster::Monster(std::shared_ptr<GameStateMediator> _mediator,  std::unique_ptr<Point> _location) : Positionable(_mediator, std::move(_location), 1)
{

}

void Monster::OnGameTick(int _userInput)
{
    int x, y;
    auto keysMap = Utils::GetKeysMap();
    assert(keysMap.contains(Qt::Key_W));
    assert(keysMap.contains(Qt::Key_S));
    assert(keysMap.contains(Qt::Key_A));
    assert(keysMap.contains(Qt::Key_D));

    x = (_userInput & keysMap.at(Qt::Key_D) - _userInput & keysMap.at(Qt::Key_A)) * mediator->options->GetMonsterSpeed() / std::sqrt(2);
    y = (_userInput & keysMap.at(Qt::Key_W) - _userInput & keysMap.at(Qt::Key_S)) * mediator->options->GetMonsterSpeed() /  std::sqrt(2);

    this->MoveBy(x, y);
}

void Monster::OnGameTick()
{
    std::cout<<"[Monster "<<id<<"] position "<<coordinates->GetX()<<", "<<coordinates->GetY()<<std::endl;
}
