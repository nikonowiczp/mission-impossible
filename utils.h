#ifndef UTILS_H
#define UTILS_H
#include "objects/positionable.h"
#include <memory>
#include <map>
#include <QKeyEvent>

class Utils
{
    public:
        static double CalculateLength(std::shared_ptr<Positionable>, std::shared_ptr<Positionable>);
        static std::map<int, int> GetKeysMap();
};

#endif // UTILS_H
