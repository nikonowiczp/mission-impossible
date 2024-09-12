#ifndef UTILS_H
#define UTILS_H
#include "objects/positionable.h"
#include <memory>
#include <map>
#include <QKeyEvent>
#define KEY_UP 0b1000
#define KEY_LEFT 0b0100
#define KEY_DOWN 0b0010
#define KEY_RIGHT 0b0001
class Utils
{
    public:
        static double CalculateLength(Positionable *, Positionable*);
        static double CalculateLength(double x1, double y1, double x2, double y2);
        static double CalculateAngle(double x1, double y1, double x2, double y2);


        static double CrossProduct(const Point& a, const Point& b, const Point& p);
        static int CountPointsOnSides(const Point& a, const Point& b, const std::vector<Positionable *>& others);

        static std::map<int, int> GetKeysMap();
        static bool IsCloseToAny(const std::vector<std::unique_ptr<Positionable> > &, double x, double y);
};

#endif // UTILS_H
