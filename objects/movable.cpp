#include <stdexcept>

#include "movable.h"
#include <cmath>
#include "utils.h"

Movable::Movable(std::shared_ptr<GameStateMediator> _mediator, std::unique_ptr<Point> _coordinates, int _id, double _range, double _speed) : Positionable(_mediator, std::move(_coordinates), _id)
{
    if (_range < 0 || _speed < 0) {
        throw std::invalid_argument("Speed and range must be positive or 0.");
    }
    this->range = _range;
    this->speed = _speed;
}

double Movable::GetRange() const
{
    return this->range;
}

double Movable::GetSpeed() const
{
    return this->speed;
}

bool Movable::MoveInDirection(double angle, const std::vector<Positionable*>& others, bool tryToAvoid) {
    double startX = this->coordinates->GetX();
    double startY = this->coordinates->GetY();

    double length = this->speed;
    if (CanMoveTo(startX + length * std::cos(angle), startY + length * std::sin(angle), others)) {
            this->coordinates = std::make_unique<Point>(startX + length * std::cos(angle), startY + length * std::sin(angle));
            return true;
    }
    if(tryToAvoid){
        for(int i = 0;i <5; i++){
            angle += 0.25* M_PI ;
            if (CanMoveTo(startX + length * std::cos(angle), startY + length * std::sin(angle), others)) {
                this->coordinates = std::make_unique<Point>(startX + length * std::cos(angle), startY + length * std::sin(angle));
                return true;
            }
        }

    }
    return false;
}

bool Movable::CanMoveTo(double newX, double newY, const std::vector<Positionable*> &others)
{
    if(newX < 0 || newX > mediator->GetGameOptions().get().GetMapWidth() || newY < 0 || newY > mediator->GetGameOptions().get().GetMapHeight()){
        return false;
    }
    for (const auto& other : others) {
        double distance = Utils::CalculateLength(newX, newY, other->GetCoordinates().GetX(), other->GetCoordinates().GetY());
        if (distance < this->Radius) {
            return false;
        }
    }
    return true;
}
