#include <cmath>
#include "utils.h"

double Utils::CalculateLength(std::shared_ptr<Positionable> _firstObject, std::shared_ptr<Positionable> _secondObject) {
    double _result = pow(_firstObject->GetCoordinates().GetX() - _secondObject->GetCoordinates().GetX(), 2);
    _result += pow(_firstObject->GetCoordinates().GetY() - _secondObject->GetCoordinates().GetY(), 2);
    return sqrt(_result);
}

std::map<int, int> Utils::GetKeysMap()
{
    std::map<int, int> _keysMap =
    {
        {Qt::Key_W, 0b1000},
        {Qt::Key_A, 0b0100},
        {Qt::Key_S, 0b0010},
        {Qt::Key_D, 0b0001}
    };
    return _keysMap;
}
