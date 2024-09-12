#ifndef POINT_H
#define POINT_H

/// 
/// \brief The Point class is a class that represents a point in 2D space.
class Point
{
public:
    ///
    /// Point constructor.
    /// @param x  Double, the x coordinate of the point.
    /// @param y  Double, the y coordinate of the point.
    Point(double x, double y);

    ///
    /// GetX is a function that returns the x coordinate of the point.
    double GetX() const;
    /// GetY is a function that returns the y coordinate of the point.
    double GetY() const;
private:
    double x = 0;
    double y = 0;
};

#endif // POINT_H
