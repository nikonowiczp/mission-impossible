#ifndef POINT_H
#define POINT_H


class Point
{
public:
    Point(int, int);
    double GetX();
    double GetY();
private:
    double x = 0;
    double y = 0;
};

#endif // POINT_H
