#ifndef POINT_H
#define POINT_H


class Point
{
public:
    Point(int, int);
    int GetX();
    int GetY();
private:
    int x = 0;
    int y = 0;
};

#endif // POINT_H
