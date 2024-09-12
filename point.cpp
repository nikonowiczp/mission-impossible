#include "point.h"

Point::Point(double _x, double _y)
{
    this->x = _x;
    this->y = _y;
}

double Point::GetX() const
{
    return this->x;
}

double Point::GetY() const
{
    return this->y;
}
