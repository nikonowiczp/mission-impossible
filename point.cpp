#include "point.h"

Point::Point(int _x, int _y)
{
    this->x = _x;
    this->y = _y;
}

double Point::GetX()
{
    return this->x;
}

double Point::GetY()
{
    return this->y;
}
