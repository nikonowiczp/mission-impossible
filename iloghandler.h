#ifndef ILOGHANDLER_H
#define ILOGHANDLER_H

#include <vector>

///
/// \brief Interface allowing to handle logs containing points achieved during one game.
///
/// ILogHandler is used to save and read game points. It's an abstraction made to separate implementation.
class ILogHandler
{
public:
    ///
    /// Basic ILogHandler constructor.
    ILogHandler();

    ///
    /// Pure virtual member to save game points.
    /// @param _points  The points achieved during game.
    virtual void SaveGame(int _points) = 0;

    ///
    /// Pure virtual member to read game points saved.
    virtual std::vector<int> ReadGames() = 0;

    ///
    /// Virtual destructor ~ILogHandler.
    virtual ~ILogHandler();
};

#endif // ILOGHANDLER_H
