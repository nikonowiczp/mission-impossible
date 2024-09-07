#include "point.h"

Point::Point(int _x, int _y)
{
    this->x = _x;
    this->y = _y;
}

int Point::GetX()
{
    return this->x;
}

int Point::GetY()
{
    return this->y;
}
