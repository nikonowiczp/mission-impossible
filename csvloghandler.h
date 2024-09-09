#ifndef CSVLOGHANDLER_H
#define CSVLOGHANDLER_H

#include "iloghandler.h"

class CSVLogHandler : public ILogHandler
{
public:
    CSVLogHandler();
    void SaveGame(int) override;
    std::vector<int> ReadGames() override;
    ~CSVLogHandler() override;
};

#endif // CSVLOGHANDLER_H
