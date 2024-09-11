#include <cmath>
#include "utils.h"

double Utils::CalculateLength(std::shared_ptr<Positionable> _firstObject, std::shared_ptr<Positionable> _secondObject) {
    return CalculateLength(_firstObject->GetCoordinates().GetX(), _firstObject->GetCoordinates().GetY(), _secondObject->GetCoordinates().GetX(), _secondObject->GetCoordinates().GetY());
}

double Utils::CalculateLength(double x1, double y1, double x2, double y2)
{
    double _result = pow(x1 - x2, 2);
    _result += pow(y1 - y2, 2);
    return sqrt(_result);
}

std::map<int, int> Utils::GetKeysMap()
{
    std::map<int, int> _keysMap =
    {
        {Qt::Key_W, KEY_UP},
        {Qt::Key_A, KEY_LEFT},
        {Qt::Key_S, KEY_DOWN},
        {Qt::Key_D, KEY_RIGHT}
    };
    return _keysMap;
}

bool Utils::IsCloseToAny(const std::vector<std::shared_ptr<Positionable> >& objects, double x, double y)
{
    for (const auto& obj : objects) {
        if (CalculateLength(obj->GetCoordinates().GetX(), obj->GetCoordinates().GetY(), x, y) < 20) {
            return false;
        }
    }
    return true;
}
