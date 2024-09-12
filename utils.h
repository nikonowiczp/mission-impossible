#ifndef UTILS_H
#define UTILS_H
#include "objects/positionable.h"
#include "enums/gamemode.h"
#include <memory>
#include <map>
#include <QKeyEvent>
#define KEY_UP 0b1000
#define KEY_LEFT 0b0100
#define KEY_DOWN 0b0010
#define KEY_RIGHT 0b0001

///
/// \brief Utils class containing general use functions.
///
/// Utils class contains public static functions that cannot be regarded as the members of the specific class.
class Utils
{
    public:
        ///
        /// Public method that calculates the distance between two Positionable objects.
        /// @param _a   Pointer to the first Positionable object.
        /// @param _b   Pointer to the second Positionable object.
        /// @return     Distance between two objects as double.
        static double CalculateLength(Positionable *_a, Positionable*_b);

        ///
        /// Public method that calculates the distance between two positions.
        /// @param x1   X coordinate of first position.
        /// @param y1   Y coordinate of first position.
        /// @param x2   X coordinate of second position.
        /// @param y2   Y coordinate of second position.
        /// @return     Distance between two objects as double.
        static double CalculateLength(double x1, double y1, double x2, double y2);        
        static double CalculateAngle(double x1, double y1, double x2, double y2);

        static double CrossProduct(const Point& a, const Point& b, const Point& p);
        static int CountPointsOnSides(const Point& a, const Point& b, const std::vector<Positionable *>& others);

        ///
        /// Public method to get the integer that represents the correlating W, A, S, D letters.
        /// @return Map of ints that represents the correlation between QT Key clicked and corresponding code.
        static std::map<int, int> GetKeysMap();

        ///
        /// Public method to get the multipier used to calculate the points of the game.
        /// @param _mode    GameMode used in the game.
        /// @return         Multiplier as double.
        static double GetDifficultyMultiplier(GameMode _mode);
        static bool IsCloseToAny(const std::vector<std::unique_ptr<Positionable> > &, double x, double y);
};

#endif // UTILS_H
