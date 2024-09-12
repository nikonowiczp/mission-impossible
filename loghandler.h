#ifndef CSVLOGHANDLER_H
#define CSVLOGHANDLER_H

#include "iloghandler.h"
#include <string>

///
/// \brief The LogHandler class implementing interface ILogHandler class.
///
/// Implementation of ILogHandler interface, allowing the games to be saved and read from the local .log file.
class LogHandler : public ILogHandler
{
public:
    ///
    /// Basic LogHandler constructor.
    LogHandler();

    ///
    /// Implementation of SaveGame function. Saves games in a "points.log" file.
    /// @param _points  Game points achieved.
    void SaveGame(int _points) override;

    ///
    /// Implementation of ReadGames function. Read games from the "points.log" file if it exists.
    /// @return Points achieved during the games as a vector of int.
    std::vector<int> ReadGames() override;

    ///
    /// Basic LogHandler destructor.
    ~LogHandler() override;
private:
    std::string filePath = "points.log";
};

#endif // CSVLOGHANDLER_H
