#ifndef ILOGHANDLER_H
#define ILOGHANDLER_H

#include <vector>

class ILogHandler
{
public:
    ILogHandler();
    virtual void SaveGame(int) = 0;
    virtual std::vector<int> ReadGames() = 0;
    virtual ~ILogHandler() = 0;
};

#endif // ILOGHANDLER_H
