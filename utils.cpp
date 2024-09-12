#include <cmath>
#include "utils.h"

double Utils::CalculateLength(Positionable* _firstObject, Positionable* _secondObject) {
    return CalculateLength(_firstObject->GetCoordinates().GetX(), _firstObject->GetCoordinates().GetY(),
                           _secondObject->GetCoordinates().GetX(), _secondObject->GetCoordinates().GetY());
}

double Utils::CalculateLength(double x1, double y1, double x2, double y2)
{
    double _result = pow(x1 - x2, 2);
    _result += pow(y1 - y2, 2);
    return sqrt(_result);
}

double Utils::CalculateAngle(double x1, double y1, double x2, double y2)
{
    return std::atan2(y2 - y1, x2 - x1);
}

double Utils::crossProduct(const Point &a, const Point &b, const Point &p)
{
    return (b.GetX() - a.GetX()) * (p.GetY() - a.GetY()) - (b.GetY() - a.GetY()) * (p.GetX() - a.GetX());
}

int Utils::countPointsOnSides(const Point &a, const Point &b, const std::vector<Point> &others)
{
    int leftSide = 0, rightSide = 0;

    for (const Point& p : others) {
        double cross = crossProduct(a, b, p);

        if (cross > 0) {
            ++leftSide; // Point is on the left side
        } else if (cross < 0) {
            ++rightSide; // Point is on the right side
        }
        // Points exactly on the line are ignored (cross == 0)
    }

    return rightSide - leftSide;
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

bool Utils::IsCloseToAny(const  std::vector<std::unique_ptr<Positionable> >& objects, double x, double y)
{
    for (const auto& obj : objects) {
        if (CalculateLength(obj->GetCoordinates().GetX(), obj->GetCoordinates().GetY(), x, y) < 20) {
            return false;
        }
    }
    return true;
}
