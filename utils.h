#ifndef UTILS_H
#define UTILS_H
#include "objects/positionable.h"
#include <memory>

class Utils
{
    public:
        static double CalculateLength(std::shared_ptr<Positionable>, std::shared_ptr<Positionable>);
};

#endif // UTILS_H
