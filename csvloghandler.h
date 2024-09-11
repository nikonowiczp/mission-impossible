#ifndef CSVLOGHANDLER_H
#define CSVLOGHANDLER_H

#include "iloghandler.h"
#include <string>

class CSVLogHandler : public ILogHandler
{
public:
    CSVLogHandler();
    void SaveGame(int) override;
    std::vector<int> ReadGames() override;
    ~CSVLogHandler() override;
private:
    std::string filePath = "logs/logs.csv";
};

#endif // CSVLOGHANDLER_H
