#include <cmath>
#include "utils.h"

double Utils::CalculateLength(std::shared_ptr<Positionable> _firstObject, std::shared_ptr<Positionable> _secondObject) {
    double _result = pow(_firstObject->GetCoordinates().GetX() - _secondObject->GetCoordinates().GetX(), 2);
    _result += pow(_firstObject->GetCoordinates().GetY() - _secondObject->GetCoordinates().GetY(), 2);
    return sqrt(_result);
}
