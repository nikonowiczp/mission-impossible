#ifndef CSVLOGHANDLER_H
#define CSVLOGHANDLER_H

#include "iloghandler.h"
#include <string>

class LogHandler : public ILogHandler
{
public:
    LogHandler();
    void SaveGame(int) override;
    std::vector<int> ReadGames() override;
    ~LogHandler() override;
private:
    std::string filePath = "points.log";
};

#endif // CSVLOGHANDLER_H
