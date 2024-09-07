#ifndef UTILS_H
#define UTILS_H
#include "objects/baseobject.h"
#include <memory>

class Utils
{
    public:
        static double CalculateLength(std::shared_ptr<BaseObject>, std::shared_ptr<BaseObject>);
};

#endif // UTILS_H
