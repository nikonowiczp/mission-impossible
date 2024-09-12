#ifndef POINT_H
#define POINT_H


class Point
{
public:
    Point(double, double);
    double GetX() const;
    double GetY() const;
private:
    double x = 0;
    double y = 0;
};

#endif // POINT_H
