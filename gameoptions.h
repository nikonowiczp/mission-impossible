#ifndef GAMEOPTIONS_H
#define GAMEOPTIONS_H

enum GameDifficulty{
    Easy = 0,
    Medium = 1,
    Hard = 2
};

///
/// \brief The GameOptions class is used to create and store all options used in game
///
class GameOptions
{
public:
    ///
    /// \brief GameOptions constructor.
    /// @param difficulty  GameDifficulty, the difficulty of the game.
    GameOptions(GameDifficulty);

    ///
    /// \brief GetHumanSpeed returns the speed of the human.
    int GetHumanSpeed() const;
    ///
    /// \brief GetHumanSight returns the sight of the human.
    /// The sight is the distance from the human to the monster when the human can see the monster.
    /// It is used to determine objects that human can see
    int GetHumanSight() const;
    ///
    /// \brief GetHumanCatch returns the catch length of the human.
    /// The catch length is the distance from the human to the monster when the human can catch the monster.
    int GetHumanCatch() const;

    ///
    /// \brief GetMonsterSpeed returns the speed of the monster.
    int GetMonsterSpeed() const;
    ///
    /// \brief GetMonsterSight returns the sight of the monster.
    int GetMonsterSight() const;

    /// 
    /// \brief GetMapWidth returns the width of the map.
    int GetMapWidth() const;
    ///
    /// \brief GetMapHeight returns the height of the map.
    int GetMapHeight() const;

    ///
    /// \brief GetHumanAmount returns the starting amount of the humans in the game.
    int GetHumanAmount() const;
    /// 
    /// \brief GetObstacleAmount returns the amount of the obstacles in the game.
    int GetObstacleAmount() const;

    ///
    /// \brief GetTicksForNewHumans returns the amount of ticks for new humans to be created.
    int GetTicksForNewHumans() const;
private:
    int humanSpeed;
    int humanSight;

    int monsterSpeed;

    int mapWidth;
    int mapHeight;

    int humanAmount;
    int obstacleAmount;

    int ticksForNewHumans;
};

#endif // GAMEOPTIONS_H
